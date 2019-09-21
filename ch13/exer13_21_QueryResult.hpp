#include<string>
#include<set>
#include<memory>
#include<vector>

class QueryResult{
	public:
		QueryResult(std::string s,
				std::shared_ptr<std::set<line_no>> p,
				std::shaired_ptr<std::vector<std::string>> f) : 
			sought(s), lines(p), file(f) {	}

		QueryResult(const QueryResult&) = delete;
		QueryResult& operator=(const QueryResult&) = delete;
		
	private:
		std::string sought;
		std::shared_ptr<std::set<line_no>> lines;
		std::shared_ptr<std::vector<std::string>> file;
};
