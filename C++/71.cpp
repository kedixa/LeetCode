class Solution {
public:
    string simplifyPath(string path) {
        /*
            将目录名逐个解析出来，若遇到'.'则什么都不做，
            若遇到'..'则向上一级，除非已经在根目录，
            若是普通目录则添加到结果中。
        */
        path += "/";
        vector<string> vec;
        int pos = 0, pos2 = path.find('/', pos + 1);
        while(pos2 != string::npos)
        {
            vec.push_back(path.substr(pos + 1, pos2 - pos - 1));
            pos = pos2;
            pos2 = path.find('/', pos + 1);
        }
        vector<string> result;
        for(auto &p : vec)
        {
            if(p == "" || p == ".");
            else if(p == "..")
            {
                if(result.size() != 0) result.pop_back();
            }
            else result.push_back(p);
        }
        string str = "/";
        str.reserve(path.length());
        if(result.size() == 0) return str;
        str = "";
        for(auto &p : result)
            str += "/" + p;
        return str;
    }
};
