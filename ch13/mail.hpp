#include<string>
#include<set>

class Folder;

class Message{
	friend class Folder;
public:

	explicit Message(const std::string &str = ""):
		contents(str) {	}
	Message(const Message &);
	Message& operator=(const Message &);
	~Message();

	void save(Folder&);
	void remove(Folder&);

	void print_debug();

private:
	std::string contents;
	std::set<Folder*> folders;

	void add_to_Folders(const Message&);
	void remove_from_Folders();

	void addFldr(Folder* f) { folders.insert(f); }
    void remFldr(Folder* f) { folders.erase(f); }
};


class Folder{
	friend class Message;
public:
	Folder(){}
	void print_debug();
	~Folder();
private:
	void add_to_Messages(const Folder&);
    void remove_from_Messages();
    void addMsg(Message* m) { msgs.insert(m); }
    void remMsg(Message* m) { msgs.erase(m); }

	std::set<Message*> msgs;
};
