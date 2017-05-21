# -*- coding:utf-8 -*-


# Design an in-memory file system to simulate the following functions:
#
# ls: Given a path in string format. If it is a file path, return a list that only contains this file's name. If it is a directory path, return the list of file and directory names in this directory. Your output (file and directory names together) should in lexicographic order.
#
# mkdir: Given a directory path that does not exist, you should make a new directory according to the path. If the middle directories in the path don't exist either, you should create them as well. This function has void return type. 
#
# addContentToFile: Given a file path and file content in string format. If the file doesn't exist, you need to create that file containing given content. If the file already exists, you need to append given content to original content. This function has void return type.
#
# readContentFromFile: Given a file path, return its content in string format.
#
# Example:
#
# Input: 
# ["FileSystem","ls","mkdir","addContentToFile","ls","readContentFromFile"]
# [[],["/"],["/a/b/c"],["/a/b/c/d","hello"],["/"],["/a/b/c/d"]]
# Output:
# [null,[],null,null,["a"],"hello"]
# Explanation:
#
#
#
#
# Note:
#
# You can assume all file or directory paths are absolute paths which begin with / and do not end with / except that the path is just "/".
# You can assume that all operations will be passed valid parameters and users will not attempt to retrieve file content or list a directory or file that does not exist.
# You can assume that all directory names and file names only contain lower-case letters, and same names won't exist in the same directory.


class FileSystem(object):

    def __init__(self):
        self.subdir = dict()
        self.content = ''
        self.file = False

    def ls(self, path):
        """
        :type path: str
        :rtype: List[str]
        """
        if path == '/' or path == '':
            res = self.subdir.keys()
            res.sort()
            return res
        if path[0] == '/':
            path = path[1:]
        index = path.find('/')
        if index < 0:
            if self.subdir[path].file:
                return [path]
            else:
                return self.subdir[path].ls('/')
        else:
            name = path[:index]
            return self.subdir[name].ls(path[index:])

    def mkdir(self, path):
        """
        :type path: str
        :rtype: void
        """
        if path == '':
            return
        if path[0] == '/':
            path = path[1:]
        index = path.find('/')
        if index < 0:
            index = len(path)
        if path[:index] not in self.subdir:
            fs = FileSystem()
            self.subdir[path[:index]] = fs
        self.subdir[path[:index]].mkdir(path[index:])

    def addContentToFile(self, filePath, content):
        """
        :type filePath: str
        :type content: str
        :rtype: void
        """
        if filePath == '':
            self.content += content
            self.file = True
            return
        if filePath[0] == '/':
            filePath = filePath[1:]
        index = filePath.find('/')
        if index < 0:
            index = len(filePath)
        if filePath[:index] not in self.subdir:
            fs = FileSystem()
            self.subdir[filePath[:index]] = fs
        self.subdir[filePath[:index]].addContentToFile(filePath[index:], content)

    def readContentFromFile(self, filePath):
        """
        :type filePath: str
        :rtype: str
        """
        if filePath == '':
            return self.content
        if filePath[0] == '/':
            filePath = filePath[1:]
        index = filePath.find('/')
        if index < 0:
            index = len(filePath)
        return self.subdir[filePath[:index]].readContentFromFile(filePath[index:])


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.ls(path)
# obj.mkdir(path)
# obj.addContentToFile(filePath,content)
# param_4 = obj.readContentFromFile(filePath)
