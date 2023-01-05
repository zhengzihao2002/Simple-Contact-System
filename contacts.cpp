#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <string>
#include <fstream>
#include <limits>
#include <typeinfo>
using namespace std;

#define MAX 1000
char sep = '\\'; // Seperation character
#define dataFile "local/data.txt" // file where local data is stored

void clearTerminal(){
    system("clear"); // clear only the visual portion
    // Message("\033c"); // completely clear the terminal screen

}
void clearInput(){
    // ONLY call this function when cin is used! not getline getchar whatever
    // try to use getline or getchar so you dont have to clearInput()

    // if there is a error in cin and cin stopped working
    if(cin.fail()){
        //clear the error state of the input stream
        cin.clear();
        //ignore any additional characters that may be in the input stream
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    // if there is still leftovers in cin buffer
    else if(cin.eof()==false){
        // or cin.peek()!=EOF
        // If the ignore function is called repeatedly and it is not encountering the delimiter character, it will get stuck in an infinite loop, causing the program to hang.
        //input not empty
        //ignore any additional characters that may be in the input stream
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

template <typename Type>
Type get() {
    // gets a value from cin
    Type value;

    if(typeid(value)==typeid(string)){
        getline(cin,value);
    }else{
        cin >> value;
        clearInput();
    }

    
    return value;

    // how to call:
    // int i = getValue<int>();
}

struct Person {
    string name;
    int sex; // 1-> Male 2-> Female
    int age;
    string cellphone;
    string addr;

};
struct ContactBook{
    // array of Persons
    struct Person personArray[MAX];
    // size of the current array
    int size; 
};

// 显示菜单
void displayMenu(){
    cout << "*******************************" <<endl;
    cout << "*******   1. Add        *******" <<endl;
    cout << "*******   2. Show       *******" <<endl;
    cout << "*******   3. Delete     *******" <<endl;
    cout << "*******   4. Find       *******" <<endl;
    cout << "*******   5. Modify     *******" <<endl;
    cout << "*******   6. Empty      *******" <<endl;
    cout << "*******   0. Exit       *******" <<endl;
    cout << "*******************************" <<endl;

}
void Message(string message){
    cout<<message<<endl;
    // consider puts(".....");
}
void MessageRed(string message){
    string newMessage ="\033[1;31m" + message + "\033[0m";
    cout<< newMessage << endl;
}
void MessageGreen(string message){
    string newMessage ="\033[1;32m" + message + "\033[0m";
    cout<< newMessage << endl;
}
void uploadData(ContactBook * book){
    // this function stores the entire Contact book in a local txt file
    
    // Open the file for writing. If the file does not exist, it will be created.
    // If it does exist, it will be overwritten.
    ofstream file(dataFile);

    // Write the struct data to the file
    for(int i=0;i<book->size;i++){
        file << book->personArray[i].name << sep << book->personArray[i].sex << sep << book->personArray[i].age  << sep << book->personArray[i].cellphone  << sep <<book->personArray[i].addr <<'\n';
    }
    // Close the file
    file.close();

}
void promptAnyKey(){
    MessageGreen("Press any key to continue...");
    getchar();
}
void add(ContactBook * book){
    if(book->size==MAX){
        Message("Action failed. The contact book is full.");
    }else{
        // 姓名
        string name;
        Message("Enter name: ");
        // clearInput();
        getline(cin,name);
        book->personArray[book->size].name = name;
        clearTerminal();

        // 性别
        int sex=0;
        while(true){
            Message("Enter sex: ");
            Message("1 --- Male");
            Message("2 --- Female");
            // clearInput(); // dont do this when before is getline not cin
            cin >> sex;

            if(cin.fail() || (sex!=1 && sex!=2)){
                clearTerminal();
                clearInput();
                Message("Unknown sex entered.");
            }else{
                break;
            }
            
        }
        book->personArray[book->size].sex = sex;
        clearTerminal();
        clearInput();

        // 年龄
        int age;
        while(true){
            Message("Enter age: ");
            // clearInput();
            cin >> age;
            if(cin.fail()||age<0){
                clearInput();
            }else{
                break;
            }
        }   
        book->personArray[book->size].age = age;
        clearTerminal();
        clearInput();

        // 手机号码
        string phone;
        Message("Enter Phone Number: ");
        // clearInput();
        cin >> phone;
        book->personArray[book->size].cellphone = phone;
        clearTerminal();
        clearInput();

        // 住址
        string address;
        Message("Enter address: ");
        getline(cin,address);
        book->personArray[book->size].addr = address;
        clearTerminal();

        // 更行通讯录的人数
        book->size++;
        clearTerminal();//clear the visible portion
        Message("Adding Person.....");
        sleep(2);clearTerminal();
    }

}
void showAll(const ContactBook * book){
    // 如果通讯录人数为0，提示为空
    if(book->size ==0){
        Message("Your contact book is empty like my wallet. Dont be a lonely dude. Try adding someone!");
    }else{
        for(int i=0;i<book->size;i++){
            cout << "name: " << book->personArray[i].name <<"\t\t";
            cout << "sex: " << (book->personArray[i].sex==1?"Male":"Female") <<"\t\t";
            cout << "age: " << book->personArray[i].age <<"\t\t";
            cout << "phone: " << book->personArray[i].cellphone <<"\t\t";
            cout << "address: " << book->personArray[i].addr <<endl;
            
        }
    }
    // clearInput();
    promptAnyKey();
    clearTerminal();
    
}
void replace(char oldChar, char newChar){
    ifstream input("local/data.txt");
    ofstream temp("local/temp.txt");

    // Read the input file character by character
    char c;
    while (input.is_open()&&input.good()&&input.get(c)) {
        // Replace '$' with '¥'
        if (c == oldChar) {
            c = newChar;
        }
        // Write the character to the output file
        temp.put(c);
    }

    input.close();
    temp.close();

    //copy temp (modified input file) into the input file
    ifstream input_file("local/temp.txt");
    ofstream output_file("local/data.txt");
    string line;
    while (getline(input_file, line)) {
        output_file << line << "\n";
    }
    input_file.close();
    output_file.close();
    remove("local/temp.txt");


}

void renderData(ContactBook * book){
    string line;
    // Open the file for reading
    ifstream file(dataFile);

    // Read the data from the file and store it in the struct. use is_open instead of good is okay too. good is used to check if its open and no errors occurred
    while(file.is_open()&&file.good()&&getline(file,line)){
        
        int prevSep;

        book->personArray[book->size].name=line.substr(0,line.find(sep));
        prevSep = line.find(sep);

        book->personArray[book->size].sex=stoi(line.substr(prevSep+1,line.find(sep,prevSep+1)-prevSep-1));
        prevSep = line.find(sep,prevSep+1);

        book->personArray[book->size].age=stoi(line.substr(prevSep+1,line.find(sep,prevSep+1)-prevSep-1));
        prevSep = line.find(sep,prevSep+1);

        book->personArray[book->size].cellphone=line.substr(prevSep+1,line.find(sep,prevSep+1)-prevSep-1);// line.find(sep,prevSep+1) =21,prevSep=17, line.substring(18,21)
        prevSep = line.find(sep,prevSep+1);
        

        book->personArray[book->size].addr=line.substr(prevSep+1,line.find(sep,prevSep+1)-prevSep-1);
        prevSep = line.find(sep,prevSep+1);
    
        book->size++;

        // why do we need "-prevSep-1" after find() method after the first?
        // explanation: substr(position,length) and find(char,startPosition), want line.substring(18,21) or [18,21)
        // line.substring ≠ line.substr
        // 2nd attrbute for line.substr is the length of the substr, may not be 21. 21 is the position of sep  meaning 18,19,20 is string. 21-17= 4, -1 then is the corret length of substring
        // reason for -1 is b/c after we remove 17 from 21, we get 18,19,20,21 and we also need to remove 21
    }
    
    // Close the file
    file.close();
}

int Index(ContactBook * book,string name){
    // this function returns the index of the name in the array of the given contactbook
    for(int i=0;i<book->size;i++){
        if(book->personArray[i].name == name){
            return i; // person is found, returns the index
        }
    }
    return -1;// person is not found
}
void Delete(ContactBook * book){
    clearTerminal();
    // clearInput();

    Message("Enter the name of the person to delete from contact: ");
    string name;
    getline(cin,name);

    clearTerminal();

    // 要删除掉的人的索引号/下标
    int index = Index(book,name);
    if(index>=0){
        MessageRed("Are you sure you want to delete "+name+"?");
        Message("Press Y/y to confirm delete, and any other key to cancel action.");

        string key;
        getline(cin,key);

        if(key.substr(0,1)=="Y" || key.substr(0,1)=="y"){
            for(int i=index;i<book->size;i++){
                // 数据前移
                book->personArray[i]=book->personArray[i+1];
            }
            book->size--;
            uploadData(book);
            Message("Sucessfully Deleted");
        }else{
            Message("Action Canceled");
        }
    }else{
        Message("Person does not exist.");
    }
}
void Find(ContactBook * book){
    clearTerminal();

    Message("Enter the name of the person to find from contact: ");
    string name;
    getline(cin,name);

    clearTerminal();

    int index = Index(book,name);
    if(index>=0){
        //存在
        cout << "name: " << book->personArray[index].name <<"\t\t";
        cout << "sex: " << (book->personArray[index].sex==1?"Male":"Female") <<"\t\t";
        cout << "age: " << book->personArray[index].age <<"\t\t";
        cout << "phone: " << book->personArray[index].cellphone <<"\t\t";
        cout << "address: " << book->personArray[index].addr <<endl;

        promptAnyKey();
        clearTerminal();
    }else{
        //不存在
        Message("Sorry. You don't have this friend.");
    }
}
void Modify(ContactBook * book){
    clearTerminal();

    Message("Enter the name of the person to modify from contact: ");
    string name;
    getline(cin,name);

    clearTerminal();

    int index = Index(book,name);
    if(index>=0){
        //存在

        int choice = 0;
        while(true){
            Message("Current Info:");
            cout << "name: " << book->personArray[index].name <<"\t\t";
            cout << "sex: " << (book->personArray[index].sex==1?"Male":"Female") <<"\t\t";
            cout << "age: " << book->personArray[index].age <<"\t\t";
            cout << "phone: " << book->personArray[index].cellphone <<"\t\t";
            cout << "address: " << book->personArray[index].addr <<endl;

            MessageGreen("Enter the part of information to modify (1-5) and any other key to exit:");
            cin >> choice;
            if(cin.fail()){
                clearInput();
                clearTerminal();
                break;
            }
            if(choice!=1 &&choice!=2 &&choice!=3 &&choice!=4 &&choice!=5){
                // any ohter than 1/2/3/4/5
                clearInput();
                clearTerminal();
                break;
            }
            clearInput();
            // If we reach here, user enters 1/2/3/4/5
            if(choice ==1){
                Message("Enter the new name:");
                string newName;
                getline(cin,newName);
                book->personArray[index].name = newName;
            }else if(choice==2){
                int sex=0;
                while(true){
                    Message("Enter new sex: ");
                    Message("1 --- Male");
                    Message("2 --- Female");
                    cin >> sex;

                    if(cin.fail() || (sex!=1 && sex!=2)){
                        clearInput();
                    }else{
                        clearInput();
                        break;
                    }
                }
                book->personArray[index].sex=sex;
            }else if(choice==3){
                int age;
                while(true){
                    Message("Enter new age: ");
                    cin >> age;
                    if(cin.fail()||age<0){
                        clearInput();
                    }else{
                        clearInput();
                        break;
                    }
                } 
                book->personArray[index].age=age;
            }
            else if(choice==4){
                string phone;
                Message("Enter new Phone Number: ");
                cin >> phone;
                book->personArray[index].cellphone = phone;
                clearInput();
            }else{
                string address;
                Message("Enter new address: ");
                getline(cin,address);
                book->personArray[index].addr = address;
            }
            uploadData(book);
            clearTerminal();
        }


    }else{
        //不存在
        Message("Sorry. You don't have this friend.");
    }

}
void Empty(ContactBook * book){
    
    clearTerminal();
    Message("To confirm, please enter the follow (cap sensitive! Failure to do so will cancel action and take you back to the home page)");
    MessageRed("I am aware that I am emptying out my contact book");
    string ans;
    getline(cin,ans);
    if(ans == "I am aware that I am emptying out my contact book"){
        // setting size to 0 will prevent user from accessing the data in the array
        book->size = 0;
        uploadData(book);
        Message("Contact Book is emptied out.");
    }else{
        Message("Action Canceled");
    }

    
}
int main(){
    // this is used to change the seperation character from $->'\'. After use, please change global variable sep to '\'
    // replace('$','\\'); return 0;

    int user = 0; // the value the user selects, default 0
    ContactBook book;
    book.size=0;
    
    renderData(&book);

    
    while(true){
        displayMenu();
        cin >> user;
        if(cin.fail()||user>6){
            // if user enters any other number not provided, or any unknown string/character, clear out cin and clear out terminal, continue looping
            clearInput();
            clearTerminal();
            continue;
        }
        // clean cin after using
        clearInput();

        switch(user){
        case 1:
            // adds a contact user
            clearTerminal();
            add(&book);
            uploadData(&book);
            break;
        case 2:
            // shows all users in your contact
            clearTerminal();
            showAll(&book);
            break;
        case 3:
            // deletes a specific contact
            Delete(&book);
            break;
        case 4:
            // finds a specific contact
            Find(&book);
            break;
        case 5:
            // modifies the information of a specific contact
            Modify(&book);
            break;
        case 6:
            // empties out your contact book
            Empty(&book);
            break;
        case 0:
            // exits the contact book
            MessageGreen("Now Exiting...");
            sleep(2);
            clearTerminal();
            MessageRed("Thanks for using SCS. Do not share this code on any platform without the permission of the owner");
            uploadData(&book);
            return 0;
        }
    }
    return 0;
}

// When you try to read a value from the input stream using std::cin, and the value entered by the user cannot be converted to the desired type (e.g. if you try to read an integer but the user enters a character), the input stream will go into an error state. If the input stream is in an error state, any subsequent calls to std::cin will be ignored until the error state is cleared.