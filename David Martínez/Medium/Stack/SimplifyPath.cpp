#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        /*
        info
            input:
                * string path, which is an absolute path starting with '/'

                * '.' refers to current directory
                * '..' refers to the diretory up a level
                * multiple consecutive '///' are treated as '/'
                * any othe format of periods is reated as file/directory name
                
                * path starts with single slash '/'
                * any two directories are separated by a single slash '/'
                * path does not end with trailing '/'
                * path only contains directories on path from root to target file/directory

            output:
                * simplified canonical path

            constraints:
                * waht range of sizes can the path have? [1, 3k]
                * what type of char can path have? lower case english letters, digits, '.','/','_'
                * path is a valid absolute unix path

        example
            path = "/home/"
            -> "/home"

            path = "/../"
            -> "/"

            path = "/home//foo/"
            -> "/home/foo"

            path = "/home/../hello"
            -> "hello"

        brute force
            have a stack

            traverse the entire path string
            / divide operations and files
                if we start constructing word and once we find '/'
                , traverse while the next value is '/' or end of string
                we check if the word is an operation
                    if word is .. we remove from stack, if stack is not empty
                    if word is . we ignore for the moment
                    else we add word to stack

            construct simplified path
            add / then word from stack until stack is empty

            complexity:
                runtime: O(n) n being each character in string
                extra space: O(number of directory/file names)

        optimize
            best conceivable runitme: O(n)

        test
            * empty path
            * path where we move into to directories and return one
            * we return a directory as first operation
                    




        */

        //get path size
        int n = path.size();

        //check path to be 1 ('/')
        if(n == 1) return "/";

        //declare variables
        stack<string> names;
        string name = "";
        string result = "/";

        //traverse path
        for(int i = 0; i <= n; i++){

            //check if we found '/'
            if(i == n || path[i] == '/'){

                //check that name is not empty
                if(name != ""){
                    //check if name is ".."
                    if(name == ".."){
                        if(!names.empty()) names.pop(); // remove word in path if its not empty
                    }
                    else if(name == "."){
                        name = "";
                    }
                    else{
                        names.push(name); //else add name to names
                    }

                    name = "";
                }
            }
            else{
                name += path[i];
            }
        }


        //construct path

        //get words
        vector<string> pathNames;
        while(!names.empty()){
            pathNames.push_back(names.top());
            names.pop();
        }

        //construct path with ordered words
        for(int i = pathNames.size() - 1; i >= 0; i--){
            result += pathNames[i];

            if(i != 0) result += "/";
        }


        return result;
    }
};

/*
time: 31 minutes

complexity:
    runtime: O(n)
    extra space: O(number of directory/file names)

Notes:
    This  problem felt easy, the part where I took most time to do was
    understanding the problem and taking notes.

    If the problem has a lot of conditions, I should either write faster or 
    simplify them as much as possible.
    Taking information from the problem took me like 8 minutes. 
    I could have finished the problem in 25 minutes

    Well performance overall.

*/