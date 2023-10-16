#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
/*
 * Node Declaration
 */

struct node
{
    string namebook;
    string auoter;
    int year;
    int price;
    struct node *next;
}*last;

/*
 * Class Declaration
 */

class circular_llist
{
    public:
       void create_node(string value1,string value2,int a1,int a2);
       void add_begin(string value1,string value2,int a1,int a2);
       void add_after(string value1,string value2,int a1,int a2, int position);
       void delete_element(string value1);
   //    void search_element(string value);
        void display_list();
   //    void update();
        void sort();
        circular_llist()
        {
            last = NULL;
        }
};

/*
 * Main :contains menu
 */
int main()
{
    int choice, element1,element2, position;

    circular_llist cl;
    while (1)
    {   string str1;
        string str2;
        cout<<endl<<"---------------------------"<<endl;
        cout<<endl<<"Circular singly linked list"<<endl;
        cout<<endl<<"---------------------------"<<endl;
        cout<<"1.Create Node"<<endl;
        cout<<"2.Add book at beginning of list"<<endl;
        cout<<"3.Add book at after of list"<<endl;
        cout<<"4.Delete the book "<<endl;
        cout<<"5.Search"<<endl;
        cout<<"6.Display"<<endl;
        cout<<"7.Update"<<endl;
        cout<<"8.Sort"<<endl;
        cout<<"9.Quit"<<endl;
        cout<<"10.display with sort year"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:

            cout<<"Enter name book:"<<endl;
            cin>>str1;
            cout<<"Enter the name of aouter: "<<endl;
            cin>>str2;
           cout<<"Enter year of print:"<<endl;
           cin>>element1;
           cout<<"Enter price of book:"<<endl;
           cin>>element2;

            cl.create_node(str1,str2,element1,element2);
            cout<<endl;
            break;
       case 2:
            cout<<"Enter name book:"<<endl;
            cin>>str1;
            cout<<"Enter the name of aouter: "<<endl;
            cin>>str2;
           cout<<"Enter year of print:"<<endl;
           cin>>element1;
           cout<<"Enter price of book:"<<endl;
           cin>>element2;
           cl.add_begin(str1,str2,element1,element2);
           cout<<endl;
           break;
       case 3:
            cout<<"Enter name book:"<<endl;
            cin>>str1;
            cout<<"Enter the name of aouter: "<<endl;
            cin>>str2;
           cout<<"Enter year of print:"<<endl;
           cin>>element1;
           cout<<"Enter price of book:"<<endl;
           cin>>element2;
           cout<<"Insert element after position:"<<endl;
           cin>>position;
           cl.add_after(str1,str2,element1,element2, position);
           cout<<endl;
           break;
      case 4:
          if (last == NULL)
          {
              cout<<"List is empty, nothing to delete"<<endl;
              break;
          }
          cout<<"Enter the namebook for deletion: ";
          cin>>str1;
          cl.delete_element(str1);
          cout<<endl;
          break;
//       case 5:
//           if (last == NULL)
//           {
//               cout<<"List Empty!! Can't search"<<endl;
//               break;
//           }
//           cout<<"Enter the element to be searched: ";
//           cin>>str;
//           cl.search_element(str);
//           cout<<endl;
//           break;
      case 6:
           cl.display_list();
           break;
//       case 7:
//           cl.update();
//           break;
//       case 8:
//       //    cl.sort();
//           break;
//       case 9:
//           exit(1);
//           break;
//       default:
//           cout<<"Wrong choice"<<endl;

        case 10:
            cl.sort();

            break;
       }
   }
    return 0;
}

/*
 * Create Circular Link List
 */
void circular_llist::create_node(string value1,string value2,int a1,int a2)
{
    struct node *temp;
    temp = new(struct node);
    temp->namebook = value1;
    temp->auoter=value2;
    temp->year=a1;
    temp->price=a2;
    if (last == NULL)
    {
        last = temp;
        temp->next = last;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}


void circular_llist::add_begin(string value1,string value2,int a1,int a2)
{
    if (last == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct node *temp;
    temp = new(struct node);
    temp->namebook = value1;
    temp->auoter=value2;
    temp->year=a1;
    temp->price=a2;
    temp->next = last->next;
    last->next = temp;
}




void circular_llist::add_after(string value1,string value2,int a1,int a2, int pos)
{
    if (last == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct node *temp, *s;
    s = last->next;
    for (int i = 0;i < pos-1;i++)
    {
        s = s->next;
        if (s == last->next)
        {
            cout<<"There are less than ";
            cout<<pos<<" in the list"<<endl;
            return;
        }
    }
    temp = new(struct node);
    temp->next = s->next;
    temp->namebook= value1;
    temp->auoter=value2;
    temp->year=a1;
    temp->price=a2;
    s->next = temp;

    if (s == last)
    {
        last=temp;
    }
}



void circular_llist::delete_element(string value)
{
    struct node *temp, *s;
    s = last->next;
      // If List has only one element
    if (last->next == last && last->namebook == value)
    {
        temp = last;
        last = NULL;
        free(temp);
        return;
    }
    if (s->namebook == value)  //First Element Deletion
    {
        temp = s;
        last->next = s->next;
        free(temp);
        return;
    }
    while (s->next != last)
    {
        //Deletion of Element in between
        if (s->next->namebook == value)
        {
            temp = s->next;
            s->next = temp->next;
            free(temp);
            cout<<"Element "<<value;
            cout<<" deleted from the list"<<endl;
            return;
        }
        s = s->next;
    }
    //Deletion of last element
    if (s->next->namebook == value)
    {
        temp = s->next;
        s->next = last->next;
        free(temp);
        last = s;
        return;
    }
    cout<<"book "<<value<<" not found this book in the list"<<endl;
}

/*
 * Search element in the list

void circular_llist::search_element(string value)
{
    struct node *s;
    int counter = 0;
    s = last->next;
    while (s != last)
    {
        counter++;
        if (s->info == value)
        {
            cout<<"Element "<<value;
            cout<<" found at position "<<counter<<endl;
            return;
        }
        s = s->next;
    }
    if (s->info == value)
    {
        counter++;
        cout<<"Element "<<value;
        cout<<" found at position "<<counter<<endl;
        return;
    }
    cout<<"Element "<<value<<" not found in the list"<<endl;
}
*/

 //* Display Circular Link List

void circular_llist::display_list()
{
    struct node *s;
    if (last == NULL)
    {
        cout<<"List is empty, nothing to display"<<endl;
        return;
    }
    s = last->next;
    cout<<"Circular Link List: "<<endl;
    while (s != last)
    {
        cout<<s->namebook<<"/"<<s->auoter<<"/"<<s->year<<"/"<<s->price<<"->"<<endl;

        s = s->next;
    }
    cout<<s->namebook<<"/"<<s->auoter<<"/"<<s->year<<"/"<<s->price<<endl;
}

/*
 * Update Circular Link List

void circular_llist::update()
{
    int value, pos, i;
    if (last == NULL)
    {
        cout<<"List is empty, nothing to update"<<endl;
        return;
    }
    cout<<"Enter the node position to be updated: ";
    cin>>pos;
    cout<<"Enter the new value: ";
    cin>>value;
    struct node *s;
    s = last->next;
    for (i = 0;i < pos - 1;i++)
    {
        if (s == last)
        {
            cout<<"There are less than "<<pos<<" elements.";
            cout<<endl;
            return;
        }
        s = s->next;
    }
    s->info = value;
    cout<<"Node Updated"<<endl;
}

/*
 * Sort Circular Link List
 */
void circular_llist::sort()
{
    struct node *s, *ptr,*h1,*h2;

    int temp;
    if (last == NULL)
    {
        cout<<"List is empty, nothing to sort"<<endl;
        return;
    }
    s = last->next;
    h2=s;
    h1=last;
    while (s != last)
    {
        ptr = s->next;
        while (ptr != last->next)
        {
            if (ptr != last->next)
            {
                if (s->year > ptr->year)
                {
                   /* temp = s->year;
                    s->year = ptr->year;
                    ptr->year = temp;*/
                   h1->next=ptr;
                   h2->next=s;
                   s->next=ptr->next;
                   ptr->next=s->next;

                }
            }
            else
            {
                break;
            }
            ptr = ptr->next;
            h2=h2->next;
        }
        s = s->next;
        h2=s;
        h1=h1->next;
    }


}
