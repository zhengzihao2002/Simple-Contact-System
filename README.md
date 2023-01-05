# Simple Contacts System (SCS)
Author: Zihao Zheng </br>
Date: 1/5/23

## 0. How to compile and run
**<span style="color:green">Compile: g++ -o contacts contacts.cpp</span>**</br>
**<span style="color:green">Run: ./contacts</span>**</br>
Please make sure that you are in the correct directory when compiling and running. The way to compile and run is one of the correct ways to do this. There may exists multiple ways to compile and run, however, the above is the recommended way.

## 1. Introdction

Contact book is a place to store phone numbers and other personal information of our friends and families.

The SCS is a C++ program that mocks the simple actions of our Contacts, which exists in many modern smartphones.

SCS has the following features:



* <span style="color:red">Add</span>：adds a contact to the contact book
* <span style="color:red">Show</span>：shows all the people and their information stored in the contact book
* <span style="color:red">Delete</span>：deletes a contacts based on given name in the contact book
* <span style="color:red">Find</span>：find a person given in the name in the contact book
* <span style="color:red">Modify</span>：modifies a persons information given the name in the contact book
* <span style="color:red">Empty</span>：Empties out the contact book
* <span style="color:red">Exit</span>：exits the contact book





## 2. Warm Tips
* The program saves information after it exits into a local text file. Do not attempt to delete it to prevent the loss of some data.
* This program has not been only tested on MacOS. May not perform as usual on any other systems other than MacOS
* Do not enter the dollar sign ($) or backslash (\\) into the information of the contact you are adding


## 3. Menu Options
```
*******************************
*******   1. Add        *******
*******   2. Show       *******
*******   3. Delete     *******
*******   4. Find       *******
*******   5. Modify     *******
*******   6. Empty      *******
*******   0. Exit       *******
*******************************
```






## 4. Exiting the program
When user enters 0, the program exits:
```
*******************************
*******   1. Add        *******
*******   2. Show       *******
*******   3. Delete     *******
*******   4. Find       *******
*******   5. Modify     *******
*******   6. Empty      *******
*******   0. Exit       *******
*******************************
0
Now Exiting...
```
Above is when "**<span style="color:skyblue">0</span>**" is entered. It displays Now Exiting.
Then, the program clears the terminal and displays the last message:
```
Thanks for using SCS. Do not share this code on any platform without the permission of the owner
```




## 5. Add a contact

The maximum number of people that could exist in the Contacts System is 1000 people. This could be modified here:
```C++
#define MAX 1000
```


The required information to add a contact includes：name, sex, age, phone number, and address.





### 5.1 Testing adding a contact

1. Start Program
```
*******************************
*******   1. Add        *******
*******   2. Show       *******
*******   3. Delete     *******
*******   4. Find       *******
*******   5. Modify     *******
*******   6. Empty      *******
*******   0. Exit       *******
*******************************
```
2. After Hitting 1 (Add Person), Terminal clears and displays instructions
```
Enter name: 
```
3. After completing all the required informations
```
Adding Person.....
```
4. Returns back to normal display
```
*******************************
*******   1. Add        *******
*******   2. Show       *******
*******   3. Delete     *******
*******   4. Find       *******
*******   5. Modify     *******
*******   6. Empty      *******
*******   0. Exit       *******
*******************************
```







## 6. Show all contacts

To show all contacts, the user must type "**<span style="color:skyblue">2</span>**" into the terminal
```
*******************************
*******   1. Add        *******
*******   2. Show       *******
*******   3. Delete     *******
*******   4. Find       *******
*******   5. Modify     *******
*******   6. Empty      *******
*******   0. Exit       *******
*******************************
2
```
```
name: Zhang Zifeng              sex: Female             age: 21         phone: N/A              address: N/A
name: Zhao Jinmai               sex: Female             age: 20         phone: N/A              address: N/A
name: Zheng Zihao               sex: Male               age: 20         phone: 6465068819               address: 北京市朝阳区
name: Bai Jingting              sex: Male               age: 29         phone: N/A              address: 北京市怀柔区
name: Wang Youjun               sex: Male               age: 25         phone: N/A              address: 河北省沧州市
name: Fu Bohan          sex: Male               age: 11         phone: N/A              address: 北京市
name: Wang Shengdi              sex: Female             age: 12         phone: N/A              address: 北京市
name: Wang Ziwen                sex: Male               age: 16         phone: 6096861586               address: 福建省福州市
Press any key to continue...
```
By hitting on any key, it takes you back to main menu



## 7. Deleting a contact

To delete a contacts, the user must type "**<span style="color:skyblue">3</span>**" into the terminal

```
*******************************
*******   1. Add        *******
*******   2. Show       *******
*******   3. Delete     *******
*******   4. Find       *******
*******   5. Modify     *******
*******   6. Empty      *******
*******   0. Exit       *******
*******************************
3
```
It will prompt you to enter the name of the person to delete. Press enter key to submit. If the person does not exist, this will show:
```
Person does not exist.
*******************************
*******   1. Add        *******
*******   2. Show       *******
*******   3. Delete     *******
*******   4. Find       *******
*******   5. Modify     *******
*******   6. Empty      *******
*******   0. Exit       *******
*******************************

```
If a person does exists, say deleting someone named "Sugar" this would show:
```
Are you sure you want to delete Sugar?
Press Y/y to confirm delete, and any other key to cancel action.
```
Press Y/y to confirm the delete, and this would show:
```
Sucessfully Deleted
*******************************
*******   1. Add        *******
*******   2. Show       *******
*******   3. Delete     *******
*******   4. Find       *******
*******   5. Modify     *******
*******   6. Empty      *******
*******   0. Exit       *******
*******************************

```




## 8. Finding a contact

To delete a contacts, the user must type "**<span style="color:skyblue">4</span>**" into the terminal

```
*******************************
*******   1. Add        *******
*******   2. Show       *******
*******   3. Delete     *******
*******   4. Find       *******
*******   5. Modify     *******
*******   6. Empty      *******
*******   0. Exit       *******
*******************************
4
```
Then, enter the name of the desired contact followed by enter key. If the user does not exists:
```
Sorry. You don't have this friend.
*******************************
*******   1. Add        *******
*******   2. Show       *******
*******   3. Delete     *******
*******   4. Find       *******
*******   5. Modify     *******
*******   6. Empty      *******
*******   0. Exit       *******
*******************************
```
If it does exists:
```
name: Zheng Zihao               sex: Male               age: 20         phone: 6465068819               address: 北京市朝阳区
Press any key to continue...
```


## 9. Modify the information of a contact

To delete a contacts, the user must type "**<span style="color:skyblue">5</span>**" into the terminal

```
*******************************
*******   1. Add        *******
*******   2. Show       *******
*******   3. Delete     *******
*******   4. Find       *******
*******   5. Modify     *******
*******   6. Empty      *******
*******   0. Exit       *******
*******************************
5
```
Then it will prompt you to enter the name of the person (cap sensitive). If the person does not exists, it will display:
```
Sorry. You don't have this friend.
*******************************
*******   1. Add        *******
*******   2. Show       *******
*******   3. Delete     *******
*******   4. Find       *******
*******   5. Modify     *******
*******   6. Empty      *******
*******   0. Exit       *******
*******************************
```
If the person does exists in your contact book, it will display the current information stored and asks for what to modify, where the numbers 1-5 represent each information respectively, eg. 1=name:
```
Current Info:
name: Zheng Zihao               sex: Male               age: 20         phone: 6465068819               address: 北京市朝阳区
Enter the part of information to modify (1-5) and any other key to exit:
```




## 10. Empty out the Contact Book
To delete a contacts, the user must type "**<span style="color:skyblue">6</span>**" into the terminal

```
To confirm, please enter the follow (cap sensitive! Failure to do so will cancel action and take you back to the home page)
I am aware that I am emptying out my contact book
```
After entering **<span style="color:red">I am aware that I am emptying out my contact book</span>**, it will display:
```
Contact Book is emptied out.
*******************************
*******   1. Add        *******
*******   2. Show       *******
*******   3. Delete     *******
*******   4. Find       *******
*******   5. Modify     *******
*******   6. Empty      *******
*******   0. Exit       *******
*******************************
```



# <span style="color:lightgreen; background-color:black" >This concludes everything for Simple Contacts System!</span>


