# include <iostream>
# include <fstream>
# include<iomanip>

using namespace std ;

class student
{
    private:

           int rno ;
           char name[50];
           int enno;
           float marks;

    public:

           void getdata ()
           {
               cout<<"\t\t\t\t\t Please Enter Student Details :"<<endl;

               cout<<"\n\n Enter The Roll Number of the student :" ;
               cin>>rno;

               cout<<"\n Enter student's Name: ";
               cin.ignore();
               cin.getline(name,50);

               cout<<"\n Enter The Enrollment Number of the student :";
               cin>>enno;

               cout<<"\nEnter The Marks of the student in Previous Year: ";
               cin>>marks;
           }   

           void showdata()
           {
               cout<<"\nRoll Number: "<<rno;

               cout<<"\nName: "<<name;

               cout<<"\nEnrollment Number : "<<enno;

               cout<<"\nMarks: "<<marks<<endl;
           }  

           int getrno()
           {
               return rno;
           } 
};

            
            void add()
            {
                student st;
                ofstream out;

                out.open("Student.txt",ios::app);
                st.getdata();
                out.write((char*) &st, sizeof(student));
                out.close();
                cout<<"\n\n\t Student record Has Been Created Succesfully." ;
                cin.ignore();
                cin.get();
                system("cls");
            }

            void display()
            {
                student st;
                ifstream in;
                in.open("Student.txt");

                cout<<"\n\t\t\t\t\t DISPLAYING ALL RECORD !!!\n\n";
                while(in.read((char*) &st, sizeof(student)))
                {
                    st.showdata();
                }
                in.close();
                cin.ignore();
                cin.get();
                system("cls");
            }

            void searchs(int n)
            {
                bool flag=false;
                student st;
                ifstream in;
                in.open("Student.txt");

                while(in.read((char*) &st, sizeof(student)))
                {
                    if(st.getrno()==n)
                    {
                        st.showdata();
                        cout<<"\n\n\n\n\n Record Found";
                        flag =true;
                    }
                }
                in.close();

                if(flag==false)
                      cout<<"\n\n Record Not Found";
                      cin.ignore();
                      cin.get();
                      system("cls");
            }

            void update(int n)
            {
                bool flag=false;
                student st;
                fstream File;
                File.open("Student.txt",ios::in|ios::out);
                while(! File.eof() && flag==false)
                {
                    File.read((char*) &st, sizeof(student));
                    if(st.getrno()==n)
                    {
                        st.showdata();
                        cout<<"\n\nPlease Enter the New Details of student"<<endl;
                        st.getdata();
                        int pos=(-1) *static_cast<int>(sizeof(st));
                        File.seekp(pos,ios::cur);
                        File.write((char*) &st, sizeof(student));
                        cout<<"\n\n\t Record Updated";
                        flag=true;
                    }
                }
                    File.close();
                    if(flag==false)
                        cout<<"\n\nRecord Not Found";
                        cin.ignore();
                        cin.get();    
                        system("cls");
            }

            void deletes (int n)
            {
                bool flag=false;
                student st;
                ifstream in;
                in.open("Student.txt");
                ofstream out;
                out.open("Temp.txt",ios::out);
                in.seekg(0,ios::beg);
                while(in.read((char*) &st, sizeof(student)))
                {
                    if(st.getrno()!=n)
                    {
                        out.write((char*) &st, sizeof(student));
                    }
                    else
                       flag=true;
                }
                out.close();
                in.close();
                remove("Student.txt");
                rename("Temp.txt","Student.txt");
                if(flag==true)
                {
                    cout<<"\n\n\t Record Deleted .";
                }
                else
                cout<<"\n\n\t Record Not Found .";
                cin.ignore();
                cin.get();
                system("cls");

            }

            int main()
            {
                int num;
                while(1)
                {
                    int c;
                    cout<<"\t\t\t Swami Vivekanand College Of Engineering , Indore \n\t\t\t\t Department of Electronic & Communication"<<endl;

                    cout<<"\n\n 1. Add a Student Data "<<endl;
                    cout<<" 2. Display Student Data "<<endl;
                    cout<<" 3. Serach Student from Records"<<endl;
                    cout<<" 4. Update Student Records "<<endl;
                    cout<<" 5.Delete Student Data frm Records"<<endl;
                    cout<<" 6. Exit"<<endl;
                    cout<<"\n\n\t Please Enter Your Choice (1-6): ";
                    cin>>c;
                    system("cls");

                    switch(c)
                    {
                        case 1:
                            add();
                            break;

                        case 2:
                            display();
                            break;

                        case 3:
                            cout<<"\n\n\t Please Enter Student's Roll Number :";
                            cin>>num;
                            searchs(num);
                            break;

                        case 4:
                            cout<<"\n\n\n\t Please Enter Student Roll Number :";
                            cin>>num;
                            update(num);
                            break;

                        case 5:
                            cout<<"\n\n\t Please Enter Student's Roll Number  ";
                            cin>>num;
                            deletes(num);
                            break;

                        case 6:
                            cout<<"\n\n\n\n\n\n\t\t\t Thanks For Using This Application  "<<endl;
                            exit (0);

                        default :
                            cout<<"\n\n\n\t\t\t Invalid Choice !!! Please Insert Proper Choice (1-6)..."<<endl<<endl<<endl<<endl;
                            system("pause");
                            system("cls");

                    }

                }


                return 0;
            }
                
            
