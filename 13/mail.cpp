/*************************************************************************
    > File Name: Mail.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月12日 星期四 16时56分16秒
 ************************************************************************/

#include<iostream>
#include <string>
#include"mail.hpp"


void Message::save(Folder &f){
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f){
	folders.erase(&f);
	f.remMsg(this);
}

//////////////////拷贝////////////////////
// add this Message to Folders that point to m
void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders) // for each Folder that holds m
        f->addMsg(this); // add a pointer to this Message to that Folder
}
// copy construct function
Message::Message(const Message &m):
    contents(m.contents), folders(m.folders) // copy message内容，并且copy message所属的folder
{
    add_to_Folders(m); // add this Message to the Folders that point to m
}


////////////////销毁//////////////////////
// remove this Message from the corresponding Folders
void Message::remove_from_Folders() {
    for (auto f : folders) // for each pointer in folders
        f->remMsg(this);   // remove this Message from that Folder
}

Message::~Message() {
    remove_from_Folders();
}


////////////////赋值//////////////////////
Message& Message::operator=(const Message &rhs)
{
    // handle self-assignment by removing pointers before inserting them
    remove_from_Folders();   // update existing Folders
    contents = rhs.contents; // copy message contents from rhs
    folders = rhs.folders;   // copy Folder pointers from rhs
    add_to_Folders(rhs);     // add this Message to those Folders
    return *this;
}

Folder::~Folder(){
    remove_from_Messages();
}

void Folder::remove_from_Messages()
{
    for (auto m : msgs) m->remFldr(this);
}

// void swap(Message &lhs, Message &rhs)
// {
//     using std::swap; // not strictly needed in this case, but good habit
//     // remove pointers to each Message from their (original) respective Folders
//     for (auto f: lhs.folders)
//         f->remMsg(&lhs);
//     for (auto f: rhs.folders)
//         f->remMsg(&rhs);
//     // swap the contents and Folder pointer sets
//     swap(lhs.folders, rhs.folders);     // uses swap(set&, set&)
//     swap(lhs.contents, rhs.contents);   // swap(string&, string&)
//     // add pointers to each Message to their (new) respective Folders
//     for (auto f: lhs.folders)
//         f->addMsg(&lhs);
//     for (auto f: rhs.folders)
//         f->addMsg(&rhs);
// }

int main(int argc, char const *argv[])
{
    std::string s = "first mail";
    // std::string s2 = "second mail";
    Message m1(s);
    // Message m2(s2);


    Folder f1;
    // Folder f2;
    m1.save(f1);
    // m1.save(f2);

    std::cout << "\n\nover\n\n" << std::endl;
    /* code */
    return 0;
}