
#include <iostream>
using namespace std;
#include <string>

struct node{
  public:
  string department;
  int number;
  string grade;
  node* next;
};

void print(node* head)
{
node* temp=head;
cout<<"Printing the course: "<<endl;
while (temp!= NULL)
{
  cout<<"Department and Course number : "<< temp->department<<" "<< temp->number<<endl;
  cout<<"Grade : "<<temp->grade<<endl;
  cout<<endl;
  temp=temp->next;
}
}

void insert(node* &head)
{
  node* temp= new node;

  cout<<"enter the department"<<endl;
  cin>>temp->department;
  cout<<"enter the course number"<<endl;
  cin>>temp->number;
  cout<<"enter the grade"<<endl;
  cin>>temp->grade;
  temp->next=NULL;
  if (head== NULL)
  {
    head=temp;   
  } 
  else 
  {
    node* previous= head;
    while (previous->next!=NULL)
    {
      previous=previous->next;
    }
    previous->next= temp;
  }
}



void remove(node* &head)
{
  node* prev= new node;
  node* temp= head;

  string department;
  bool remove= false;
  int number;
  cout<<"enter the department and course number to remove"<<endl;
  cin>> department;
  cin>>number;
  if(temp==NULL)
  {
    return;
  }
  else if (department==temp->department && number==temp->number)
  {
    delete temp;
    head= temp->next;
  }
  else 
  {
    while (temp!= NULL && remove==false)
    {
      if(department==temp->department && number==temp->number)
      {
       remove=true;
      }
      else
      {
       prev= temp;
       temp=temp->next;
      }
    }  
    prev->next=temp->next;
    delete temp; 
  } 
}




  void displayDepartment(node* head)
  {
    string department;
    node* temp= head;
  cout<<"enter the department to search \n";
  cin>> department;
  while (temp!=NULL)
  {
    if(department== temp->department)
    {
      cout<<temp->department<< " "<< temp->number<< endl;
      cout<<"Grade :"<< temp->grade<<endl;
    }
    temp=temp->next;
  }
  } 


  void calculateGpa(node* head)
  {
    node* temp=head;
    string grade;
    float total=0;
    float gpa;
    float counter=0;
    while(temp!= NULL)
    {
    grade=temp->grade;
    if(grade=="A")
    {
      total+=4.00;
    }
    else if (grade=="A-")
    {
      total+=3.67;
    }
    else if (grade=="B+")
    {
      total+=3.33;
    }
    else if (grade=="B")
    {
      total+=3.00;
    }
    else if (grade=="B-")
    {
      total+=2.67;
    }
    else if (grade=="C+")
    {
      total+=2.33;
    }
    else if (grade=="C")
    {
      total+=2.00;
    }
    else if (grade=="C-")
    {
      total+=1.67;
    }
    else if (grade=="D+")
    {
      total+=1.33;
    }
    else if (grade=="D")
    {
      total+=1.00;
    }
    else if (grade=="D-")
    {
      total+=0.67;
    }
    else if (grade=="F")
    {
      total+=0.0;
    }
    temp=temp->next;
     counter++;
    }
    gpa=total/counter;
    cout<<"GPA : "<<gpa<<endl;
  }




int main() {
  node* head= new node;
  head= NULL;
  int choice;
  do{
  cout << "Select option: " << endl << endl;
    cout << "1. Print the list" << endl;
    cout << "2. Insert a course" << endl;
    cout << "3. Remove a course" << endl;
    cout << "4. Print course from department" << endl;
    cout<<"5. Calculate gpa"<<endl;
    cout<<"6. Quit"<< endl;
    cin>>choice;
    if (choice==1)
    {
      print(head);
    }
    else if(choice==2)
    {
      insert(head);
    }
    else if (choice==3)
    {
      remove(head);
    }
    else if (choice==4)
    {
      displayDepartment(head);
    }
    else if(choice==5)
    {
      calculateGpa(head);
    }

    else if(choice==6)
    {
      cout<<"Thank you"<<endl;
    }
  }
  while(choice!=6);
}
