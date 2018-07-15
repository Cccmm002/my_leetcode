//
// Equations are given in the format A / B = k, where  A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.
//
// Example:
// Given  a / b = 2.0, b / c = 3.0. queries are:  a / c = ?,  b / a = ?, a / e = ?,  a / a = ?, x / x = ? . return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
//
//
// The input is:  vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return  vector<double>.
//
//
// According to the example above:
// equations = [ ["a", "b"], ["b", "c"] ],
// values = [2.0, 3.0],
// queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
//
//
//
// The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
//


import javafx.util.Pair;

class Solution {
    private void insertGraph(Map<String, Map<String, Double>> graph, String a, String b, double v) {
        if (graph.containsKey(a)) {
            graph.get(a).put(b, v);
        }
        else {
            Map<String, Double> item = new HashMap<>();
            item.put(b, v);
            graph.put(a, item);
        }
    }
    
    double bfs(Map<String, Map<String, Double>> graph, String a, String b) {
        if (a.equals(b))
            return 1.0;
        Queue<Pair<String, Double>> q = new ArrayDeque<>();
        Set<String> visited = new HashSet<>();
        q.add(new Pair(a, 1.0));
        visited.add(a);
        while (!q.isEmpty()) {
            Pair<String, Double> p = q.poll();
            String current = p.getKey();
            double value = p.getValue();
            if (current.equals(b))
                return value;
            for (Map.Entry<String, Double> e : graph.get(current).entrySet()) {
                String s = e.getKey();
                double multi = e.getValue();
                if (visited.contains(s))
                    continue;
                q.add(new Pair(s, multi*value));
                visited.add(s);
            }
        }
        return -1.0;
    }
    
    public double[] calcEquation(String[][] equations, double[] values, String[][] queries) {
        int given = values.length;
        int count_queries = queries.length;
        Map<String, Map<String, Double>> graph = new HashMap<>();
        Set<String> appear = new HashSet<>();
        for (int i = 0; i < given; i++) {
            String a = equations[i][0];
            String b = equations[i][1];
            insertGraph(graph, a, b, values[i]);
            insertGraph(graph, b, a, 1.0/values[i]);
            appear.add(a);
            appear.add(b);
        }
        double[] results = new double[count_queries];
        for (int i = 0; i < count_queries; i++) {
            if (!appear.contains(queries[i][0]))
                results[i] = -1.0;
            else
                results[i] = bfs(graph, queries[i][0], queries[i][1]);
        }
        return results;
    }
}
