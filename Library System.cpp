#include <iostream>
#include <string>
#include <limits> // to clear the input buffer
#include <fstream>

using namespace std;
class Library{
	private:
	   string isbn;    //Represents the International Standard Book Number of the book.(978-93-96055-02-6)
	   string title;
	   string author;
	   string edition;
	   string publication;
	   int noOfBooks;
	   
	   public:
	   bool available;
	    Library() {
	    	isbn = "-";  
		    title = "-";
		    author = "-";
		    edition = "-";
		    publication = "-";
	    	available = false;
	    	noOfBooks = 0;
	   }
	   
	public:
//Functions that set the value of the private data variables.
	   void setIsbn(string i) {
	   	    isbn = i;
	   }
	   
	   void setTitle(string t) {
	   	    title = t;
	   } 
	   
	   void setAuthor(string a) {
	   	    author = a;
	   }
	   
	   void setEdition(string e) {
	   	    edition = e;
	   }
	   
	   void setPublication(string p) {
	   	    publication = p;
	   }
	   
	   void setNoOfBooks(int n){
	   		noOfBooks = n;
	   }
	   
	   
//Functions that get the value or return the value.

       string getIsbn() {
     	   return isbn;
	    }
	 
	    string getTitle() {
	 	   return title;
	    }
	 
	    string getAuthor() {
	 	   return author;
	    }
	    
	    string getEdition() {
	    	return edition;
		}
	 
	    string getPublication() {
	    	return publication;
		}
		
		int getNoOfBooks(){
	   		return noOfBooks;
	   	}
	   	
};

//global declaration of function to be used. 
void addBooks();
void deleteBooks();
void editBooks();
void searchBooks();
void viewAllBooks();
void borrowBook();
void returnBook();
void read();
void write();
void quit();


const int size = 50;
Library books[size];

int main() {
   // write();   // USE TO SET UP A NEW FILE
	string choice;
	string stu_ID;
	string stu_password;
	string librarian="Ahmed", librarian_pass="123"; //Password to login as librarian
	string select;
	
	cout<<" \t\t\t\t ---------------------------------------------------- " <<endl;
	cout<<" \t\t\t\t\t WELCOME TO LIBRARY MANAGEMENT SYSTEM   "  <<endl;
	cout<<" \t\t\t\t\t  THIS SYSTEM IS MADE BY ESHA KHALID    " <<endl;
	cout<<" \t\t\t\t ---------------------------------------------------- " <<endl;
	cout<<endl <<endl;
	
    cout<<endl;
    cout<<" [1] PRESS 1 FOR LIBRARIAN.  "       <<endl <<endl;
	cout<<" [2] PRESS 2 FOR STUDENTS.       "   <<endl <<endl;
	cout<<" [3] PRESS 3 FOR QUIT THE PROGRAM. " <<endl;
		
/* If you used cin >> choice, it would only capture the first word until a space is ened. 
getline allows you to capture the entire line, including spaces.
thats why we use getline function.
*/
 
	cout<<endl <<" Enter your choice here : ";
    getline(cin , select);
    
    
// if for librarian
	if(select == "1") {	
		cout<<endl <<" Enter Librarian Name : ";
		getline(cin , librarian);
		cout<<endl <<" Enter Password       : ";
		getline(cin , librarian_pass);
		if(librarian == "Ahmed" && librarian_pass == "123"){			
			cout<<endl <<" LOGIN SUCCESSFULLY! " <<endl;
		    do
			{  
			    cout<<endl <<" ------------ LIBRARIAN LOGIN  ------------ " <<endl;				
				cout<<endl <<endl;
				cout<<" [1] PRESS 1 TO ADD A BOOK.       " <<endl;
				cout<<" [2] PRESS 2 TO DELETE A BOOK.    " <<endl;
				cout<<" [3] PRESS 3 TO EDIT A BOOK.      " <<endl;
				cout<<" [4] PRESS 4 TO SEARCH A BOOK.    " <<endl;
				cout<<" [5] PRESS 5 TO VIEW ALL BOOKS.   " <<endl;
				cout<<" [6] PRESS 6 TO QUIT.             " <<endl <<endl;			
				cout<<" Enter your choice here : ";
				
			    getline(cin , choice);
				system("cls");

				if(choice == "1") {
			   	    addBooks();
				}
			   
				else if(choice == "2") {
			   	    deleteBooks();
				}
			   
				else if(choice == "3") {
			   	    editBooks();
				}
			   
				else if(choice == "4") {
			   	    searchBooks();
				}
			    
				else if(choice == "5") {
			   	    viewAllBooks();
				}
			   
				else if(choice == "6"){
				   	system(" cls ");
			   	    main();
				}
				else{
			   	    cout<<" WRONG CHOICE.!!!! " <<endl <<endl;		   	    
			   	    system(" pause "); 
				}
				system("cls");
			}while(choice != "6");
		}
		else if(librarian == "Ahmed" && librarian_pass != "123") {
			cout<<endl <<" WRONG NAME OR PASSWORD " <<endl;
		}
		else if(librarian != "Ahmed" && librarian_pass == "123") {
			cout<<endl <<" WRONG NAME OR PASSWORD " <<endl;
		}
		else{
			cout<<endl <<" WRONG NAME OR PASSWORD " <<endl;
			system("pause");
			system("cls");
			main();
		}	
	}
// if for student	
else if (select == "2") {
    cout << endl << " Enter Student Name : ";
    getline(cin, stu_ID);

    cout << endl << " Enter Password     : ";
    getline(cin , stu_password);

    bool validID = false;
    for (int i = 0; i < stu_ID.length(); i++) {
         
		if(stu_ID[i] >= 'A' && stu_ID[i] <= 'Z' || stu_ID[i] >= 'a' && stu_ID[i] <= 'z'){
            validID = true;
            break;
        }
    }

    bool validPassword = (stu_password.length() == 6);

    if (validID && validPassword) {
        cout<<endl << " LOGIN SUCCESSFULLY! " << endl;
    
        do {
            cout << endl << " ------------ STUDENT LOGIN  ------------ " << endl << endl;

            cout << endl;
            cout << endl << " [1] PRESS 1 TO VIEW ALL BOOKS.   " << endl;
            cout << endl << " [2] PRESS 2 TO SEARCH A BOOK.    " << endl;
            cout << endl << " [3] PRESS 3 TO BORROW BOOK.      " << endl;
            cout << endl << " [4] PRESS 4 TO RETURN BOOK.      " << endl;
            cout << endl << " [5] PRESS 5 TO GO BACK TO MAIN MENU. " << endl;

            cout << endl << " Enter your choice here : ";
            getline(cin, choice);

            system("cls");

            if (choice == "1") {
                viewAllBooks();
            } 
			else if (choice == "2") {
                searchBooks();
            } 
			else if (choice == "3") {
                borrowBook();
            } 
			else if (choice == "4") {
                returnBook();
            } 
			else if (choice == "5") {
                main();
            }
            system("cls");
        }
		 while (choice != "5");
        
 }
         
        else if(!validID || !validPassword) {
        cout<<endl << " WRONG STUDENT NAME OR PASSWORD " << endl;
        }
    
}
 		
// if to quit
    else if(select == "3") {
   	   quit();
	}
    else{
   	    cout<<" WRONG CHOICE.!!" <<endl <<endl;   	    
   	    system(" pause ");
	   	system(" cls ");
	}
     
	return 0;
}

//function for add book
void addBooks() {
   string isbn;   
   string title;
   string author;
   string edition;
   string publication;
   int numOfBooks;
   read();
   
	   
   cout<<endl <<" ---------------- ADD BOOK ---------------- " <<endl <<endl;
   
   	for(int i = 0 ; i < size ; i++){
   		if(books[i].getIsbn()=="-"){ // loop start
	   	    cout<<" ENTER INTERNATIONAL STANDARD BOOK NUMBER : ";
	   	    getline(cin , isbn);
	   	    
	   	    cout<<" ENTER BOOK TITLE                         : ";
	   	    getline(cin , title);
	   	    
	   	    cout<<" ENTER BOOK AUTHOR                        : ";
	   	    getline(cin , author);
		   	    
	   	    cout<<" ENTER BOOK EDITION                       : ";
	   	    getline(cin , edition);
	   	    
	   	    cout<<" ENTER BOOK PUBLICATION                   : ";
	   	    getline(cin , publication);
	   	    
	   	    cout<<" ENTER NUMBER OF BOOKS                    : ";
	   	    cin>>numOfBooks;
	   	    
	   	    books[i].setIsbn(isbn);
            books[i].setTitle(title);
            books[i].setAuthor(author);
            books[i].setEdition(edition);
            books[i].setPublication(publication);
            books[i].setNoOfBooks(numOfBooks);
            if(books[i].getNoOfBooks() > 0){
            	books[i].available = true;           	
			}else{
				books[i].available = false; 
			}
//File open to write data
 			ofstream fout("Library.txt");
       		if (fout.is_open()){
	       		for (int j = 0; j < size; j++) {
	            	fout << books[j].getIsbn()<<"\t\t"<<books[j].getTitle()<<"\t\t"<<books[j].getAuthor()<<"\t\t"<<books[j].getEdition()<<"\t\t"<<books[j].getPublication()<<"\t\t"<<books[j].getNoOfBooks()<<"\t\t"<<books[j].available<<endl;
	           	}
			}     
			fout.close();   
//File closed here			   						          	    
	   	    cout<<endl <<" BOOK ADDED SUCCESSFULLY! " <<endl;	   	 
			   cin.ignore(numeric_limits<streamsize>::max(), '\n'); //to clear input buffer/memory   
	       system(" pause ");
	       break;
		}
		else if(books[i].getIsbn()!="-" && i==size-1){ //Condition if not a single slot is - in library
			cout<<endl <<" MAXIMUM BOOK LIMIT REACHED " <<endl;	
		}
	}// loop end
}

//function for delete book
void deleteBooks() { 
	string isbn;
	read();	
	cout<<endl <<" ---------------- DELETE BOOK ---------------- " <<endl <<endl;
	
	cout<<" ENTER INTERNATIONAL STANDARD BOOK NUMBER : ";
	getline(cin , isbn);
		
		for(int i = 0; i < size; i++) { // loop start			
			if(books[i].getIsbn() == isbn) {
				cout<<" BOOK FOUND! " <<endl;
				
				cout<<" Do you want to delete this book? " <<endl;
				
				cout<<" Press 1 for YES. " <<endl;
				cout<<" Press 2 for NO.  " <<endl;
				char choose;
				cin>>choose;

				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //to clear input buffer/memory
				
				if(choose == '1') {
					books[i].setIsbn("-");
					books[i].setTitle("-");
					books[i].setAuthor("-");
					books[i].setEdition("-");
					books[i].setPublication("-");
					books[i].setNoOfBooks(0);
					books[i].available = false;
//File open to write data					
					ofstream fout("Library.txt");
		       		if (fout.is_open()){
			       		for (int j = 0; j < size; j++) {
			            	fout << books[j].getIsbn()<<"\t\t"<<books[j].getTitle()<<"\t\t"<<books[j].getAuthor()<<"\t\t"<<books[j].getEdition()<<"\t\t"<<books[j].getPublication()<<"\t\t"<<books[j].getNoOfBooks()<<"\t\t"<<books[j].available<<endl;
			           	}
					}     
					fout.close();
//File closed here	 					
					cout<<endl <<" BOOK DELETED SUCCESSFULLY! " <<endl;
	   	            system(" pause ");
	   	            break;
				}else break;
	    	}else if(books[i].getIsbn() != isbn && i==size-1){ //Condition if book is not in library
	    		cout<<" BOOK NOT FOUND! "<<endl;
	    		system(" pause ");
			}	    
		}  // end for loop	
}

// function for edit book
void editBooks() {
    string edit_isbn;
    string isbn;
    string title;
    string author;
    string edition;
    string publication;
    string choice;
    int numOfBooks;

    // Reading File (Assuming this is a globally declared array)
    read();

    cout << endl << " ---------------- EDIT BOOK ---------------- " << endl << endl;

    cout << " ENTER INTERNATIONAL STANDARD BOOK NUMBER : ";
    getline(cin, edit_isbn);

    bool bookFound = false;

    for (int i = 0; i < size; i++) {
        if (books[i].getIsbn() == edit_isbn) {
            cout << " BOOK FOUND! " << endl;

            cout << " Do you want to edit this book? " << endl;
            cout << " Press 1 for YES. " << endl;
            cout << " Press 2 for NO.  " << endl;
            getline(cin, choice);

            if (choice == "1") {
                cout << " [1] Press For Edit ISBN. " << endl;
                cout << " [2] Press For Edit Title. " << endl;
                cout << " [3] Press For Edit Author. " << endl;
                cout << " [4] Press For Edit Edition. " << endl;
                cout << " [5] Press For Edit Publication. " << endl;
                cout << " [6] Press For Edit No Of Books. " << endl;

                getline(cin, choice);

                if (choice == "1") {
                    cout << " ENTER INTERNATIONAL STANDARD BOOK NUMBER : ";
                    getline(cin, isbn);
                    books[i].setIsbn(isbn);
                } else if (choice == "2") {
                    cout << " ENTER BOOK TITLE                         : ";
                    getline(cin, title);
                    books[i].setTitle(title);
                } else if (choice == "3") {
                    cout << " ENTER BOOK AUTHOR                        : ";
                    getline(cin, author);
                    books[i].setAuthor(author);
                } else if (choice == "4") {
                    cout << " ENTER BOOK EDITION                       : ";
                    getline(cin, edition);
                    books[i].setEdition(edition);
                } else if (choice == "5") {
                    cout << " ENTER BOOK PUBLICATION                   : ";
                    getline(cin, publication);
                    books[i].setPublication(publication);
                } else if (choice == "6") {
                    cout << " ENTER NUMBER OF BOOKS                    : ";
                    cin >> numOfBooks;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    books[i].setNoOfBooks(numOfBooks);

                    if (books[i].getNoOfBooks() > 0) {
                        books[i].available = true;
                    } else {
                        books[i].available = false;
                    }
                }

                // File open to write data (use ios::out to overwrite the file)
                ofstream fout("Library.txt", ios::out);
                if (fout.is_open()) {
                    for (int j = 0; j < size; j++) {
                        fout << books[j].getIsbn() << "\t\t" << books[j].getTitle() << "\t\t" << books[j].getAuthor() << "\t\t" << books[j].getEdition() << "\t\t" << books[j].getPublication() << "\t\t" << books[j].getNoOfBooks() << "\t\t" << books[j].available << endl;
                    }
                    fout.close();
                    cout << endl << " BOOK EDIT SUCCESSFULLY! " << endl;
                    bookFound = true;
                } else {
                    cout << "Error opening file for writing!" << endl;
                }

                system("pause");
                break;
            } else {
                // User chose not to edit
                bookFound = true;
                break;
            }
        }
    }

    if (!bookFound) {
        cout << " BOOK NOT FOUND! " << endl;
    }
}


//function for search book
void searchBooks() {
	string isbn;
	read(); // Reading File
	
	cout<<endl <<" ---------------- SEARCH BOOK ---------------- " <<endl <<endl;	
	
	cout<<" ENTER INTERNATIONAL STANDARD BOOK NUMBER : ";
	getline(cin , isbn);
	
	for(int i = 0; i < size; i++) {
		
		if(books[i].getIsbn() == isbn) {
			
			cout<<" BOOK FOUND! " <<endl <<endl;
			
			cout<<" INTERNATIONAL STANDARD BOOK NUMBER : " <<books[i].getIsbn()        <<endl;
			cout<<" TITLE                              : " <<books[i].getTitle()       <<endl;
			cout<<" AUTHOR                             : " <<books[i].getAuthor()      <<endl;
			cout<<" EDITION                            : " <<books[i].getEdition()     <<endl;
			cout<<" PUBLICATION                        : " <<books[i].getPublication() <<endl;
			cout<<" NUMBER OF BOOKS                    : " <<books[i].getNoOfBooks() <<endl;
			cout<<" AVAILABLE                          : " << boolalpha << books[i].available << endl;
			system(" pause ");
			system(" cls ");
			break;
		}else if(books[i].getIsbn() != isbn && i==size-1){
			cout<<" BOOK NOT FOUND. " <<endl;			
			system(" pause ");			
		}			
	} // end for loop
	
}

//function for view book
void viewAllBooks() {
	read(); // Reading File
	cout<<endl <<" ---------------- All BOOKS ---------------- " <<endl <<endl;		
		for(int i = 0; i < size; i++) {  // start for loop			
			if(books[i].getIsbn() != "-"){
				cout<<endl <<" -------- BOOK DETAILS -------- " <<endl <<endl;
				cout<<" INTERNATIONAL STANDARD BOOK NUMBER : " <<books[i].getIsbn()        <<endl;
				cout<<" TITLE                              : " <<books[i].getTitle()       <<endl;
				cout<<" AUTHOR                             : " <<books[i].getAuthor()      <<endl;
				cout<<" EDITION                            : " <<books[i].getEdition()     <<endl;
				cout<<" PUBLICATION                        : " <<books[i].getPublication() <<endl;
				cout<<" NUMBER OF BOOKS                    : " <<books[i].getNoOfBooks() <<endl;
				cout<<" AVAILABLE                          : " << boolalpha << books[i].available << endl;
			
		} // end for loop		
	} // end else
		system(" pause ");	
	
}

//function to borrow a book
void borrowBook() {
    string isbn;
	read(); // Reading File
    cout << endl << " ---------------- BORROW BOOK ---------------- " << endl << endl;

    cout << " ENTER INTERNATIONAL STANDARD BOOK NUMBER : ";
    getline(cin, isbn);

    for (int i = 0; i < size; i++) {

        if (books[i].getIsbn() == isbn) {
            if (books[i].available) {
                cout << " BOOK FOUND! " << endl << endl;
                cout << " INTERNATIONAL STANDARD BOOK NUMBER : " << books[i].getIsbn() << endl;
                cout << " TITLE                              : " << books[i].getTitle() << endl;
                cout << " AUTHOR                             : " << books[i].getAuthor() << endl;
                cout << " EDITION                            : " << books[i].getEdition() << endl;
                cout << " PUBLICATION                        : " << books[i].getPublication() << endl;
                cout<<" NUMBER OF BOOKS                    : " <<books[i].getNoOfBooks() <<endl;
				cout<<" AVAILABLE                          : " << boolalpha << books[i].available << endl;

                char borrow;
                cout << " DO YOU WANT TO BORROW THIS BOOK? (Y/N): ";
                cin >> borrow;

                // Clear the input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (borrow == 'Y' || borrow == 'y') {
                	int x = books[i].getNoOfBooks();
                	x--;
                	books[i].setNoOfBooks(x);
                	if(books[i].getNoOfBooks() > 0){
		            	books[i].available = true;           	
					}else{
						books[i].available = false; 
					}
//File open to write data
                    ofstream fout("Library.txt");
		       		if (fout.is_open()){
			       		for (int j = 0; j < size; j++) {
			            	fout << books[j].getIsbn()<<"\t\t"<<books[j].getTitle()<<"\t\t"<<books[j].getAuthor()<<"\t\t"<<books[j].getEdition()<<"\t\t"<<books[j].getPublication()<<"\t\t"<<books[j].getNoOfBooks()<<"\t\t"<<books[j].available<<endl;
			           	}
					}     
					fout.close(); 
//File closed here
                    cout << " BOOK SUCCESSFULLY BORROWED" << endl;
                    system(" pause ");
                    break;
                }
            } else {
                cout << " BOOK NOT AVAILABLE" << endl;
                break;
            }
        } else if (books[i].getIsbn() != isbn && i == size - 1) {
            cout << " BOOK NOT FOUND. " << endl;
            system(" pause ");
        }
    }
}

//function to return a book
void returnBook(){
    string isbn;
	read(); // Reading file
    cout << endl << " ---------------- RETURN BOOK ---------------- " << endl << endl;
    cout << " ENTER INTERNATIONAL STANDARD BOOK NUMBER : ";
    getline(cin, isbn);

    for (int i = 0; i < size; i++) { // loop start
       
        if (books[i].getIsbn() == isbn) {
                cout << " INTERNATIONAL STANDARD BOOK NUMBER : " << books[i].getIsbn() << endl;
                cout << " TITLE                              : " << books[i].getTitle() << endl;
                cout << " AUTHOR                             : " << books[i].getAuthor() << endl;
                cout << " EDITION                            : " << books[i].getEdition() << endl;
                cout << " PUBLICATION                        : " << books[i].getPublication() << endl;

                char Return;
                cout << " DO YOU WANT TO RETURNED THIS BOOK? (Y/N): ";
                cin >> Return;

                // Clear the input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (Return == 'Y' || Return == 'y') {
                	int x = books[i].getNoOfBooks();
                	x++;
                	books[i].setNoOfBooks(x);
                	if(books[i].getNoOfBooks() > 0){
		            	books[i].available = true;           	
					}else{
						books[i].available = false; 
					}
//File open to write data
                    ofstream fout("Library.txt");
		       		if (fout.is_open()){
			       		for (int j = 0; j < size; j++) {
			            	fout << books[j].getIsbn()<<"\t\t"<<books[j].getTitle()<<"\t\t"<<books[j].getAuthor()<<"\t\t"<<books[j].getEdition()<<"\t\t"<<books[j].getPublication()<<"\t\t"<<books[j].getNoOfBooks()<<"\t\t"<<books[j].available<<endl;
			           	}
					}     
					fout.close(); 
//File closed here
                    cout << " BOOK SUCCESSFULLY RETURNED" << endl;
                    system(" pause ");
                    break;
                }
          
        } else if (books[i].getIsbn() != isbn && i == size - 1) {
            cout << " BOOK NOT FOUND. " << endl;
            system(" pause ");
        }
    } // loop end	
}

//function for quit book
void quit() {
//// exit(1) is use to exit our program 
	exit(1);
}

// Read from File Function
void read() {
    ifstream fin;
    string isbn, title, author, edition, publication;
    int numOfBooks;
    bool available;
	fin.open("Library.txt");
    if (!fin) {
        cout << "Error opening file 'Library.txt'" << endl;
    } else {
        for (int i = 0; i < size; i++) {
            fin >> isbn >> title >> author >> edition >> publication >> numOfBooks >> available;
            books[i].setIsbn(isbn);
            books[i].setTitle(title);
            books[i].setAuthor(author);
            books[i].setEdition(edition);
            books[i].setPublication(publication);
            books[i].setNoOfBooks(numOfBooks);
            books[i].available = available;
        }
        fin.close();
        cout << "Data successfully read from 'Library.txt'" << endl;
    }
}

void write(){
    ofstream fout;
    bool available;
	fout.open("Library.txt");
    if (!fout) {
        cout << "Error opening file 'Library.txt'" << endl;
    } else {
        for (int j = 0; j < size; j++) {
            fout << books[j].getIsbn()<<"\t\t"<<books[j].getTitle()<<"\t\t"<<books[j].getAuthor()<<"\t\t"<<books[j].getEdition()<<"\t\t"<<books[j].getPublication()<<"\t\t"<<books[j].getNoOfBooks()<<"\t\t"<<books[j].available<<endl;
        }
        fout.close();
        cout << "File Created Successfully 'Library.txt'" << endl;
    }	
}
