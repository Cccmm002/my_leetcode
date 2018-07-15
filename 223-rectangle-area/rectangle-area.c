// Find the total area covered by two rectilinear rectangles in a 2D plane.
//
// Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
//
//
//
// Example:
//
//
// Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
// Output: 45
//
// Note:
//
// Assume that the total area is never beyond the maximum possible value of int.
//


int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int a1 = (C-A)*(D-B);
    int a2 = (G-E)*(H-F);
    if(E>=C || F>=D || G<=A || H<=B) {
        return a1 + a2;
    }
    int m = G>C?C:G;
    int n = H>D?D:H;
    int x = E<A?A:E;
    int y = F<B?B:F;
    int a = (m-x)*(n-y);
    return a1 + a2 - a;
}
