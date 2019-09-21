#include<fstream>
#include<string>
#include<vector>
#include<memory>
#include<map>
#include<set>
class QueryResult;

class TextQuery{
	public:
		using line_no = std::vector<std::string>::size_type;

        TextQuery(const TextQuery&) = delete;
        TextQuery& operator=(const TextQuery&) = delete;

		TextQuery(std::ifstream&);
		QueryResult query(const std::string &) const;
	private:
		// the contents of file
		std::shared_ptr<std::vector<std::string>> file;
		std::map<std::string,
			std::shared_ptr<std::set<line_no>>> wm;
};

