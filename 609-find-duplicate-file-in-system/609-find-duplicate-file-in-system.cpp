class Solution {
public:
  vector<vector<string>> findDuplicate(vector<string>& paths) {
    unordered_map<string, vector<string>> files;
    for (auto path : paths) {
	    stringstream ss(path);
	    string root;
	    string s;
	    getline(ss, root, ' ');
	    while (getline(ss, s, ' ')) {
		    string fileName = root + '/' + s.substr(0, s.find('('));
		    string fileContent = s.substr(s.find('(') + 1, 
                                          s.find(')') - s.find('(') - 1);
		    files[fileContent].push_back(fileName);
	    }
    }
    vector<vector<string>> answer;
    for (const auto [fileContent , fileName] : files) {
	    if (fileName.size() > 1)
		    answer.push_back(fileName);
    }

    return answer;
  }
};