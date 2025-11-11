#include <iostream>
#include <string>
using namespace std;

// forward declaration
template<typename T,int N> class stack;
template<typename T,int N> void add(stack<T,N>& s);
template<typename T,int N> void pop(stack<T,N>& s);

template<typename T,int N>
struct menu_item
{
    const string label;
    void(*action)(stack<T,N>&);
};

template<typename T,int N>
class stack
{
    public:
        stack();
        int get_size()const{return size;}
        void print_stack()const;
        bool push(T value);
        bool pop(T *element);

    private:
        int size;
        int top;
        T array[N];

};

int main()
{
    stack<float,10> stack1;
    // Menu
    const menu_item<float,10> menu[]=
    {
        {"Add",add<float,10>},
        {"Pop",pop<float,10>},
    };

    while(1)
    {

        int option;
        stack1.print_stack();
        cout<<"Choose :\n1.Add\n2.Pop"<<endl;
        cin>>option;
        cout << "\033[H\033[J";//clear screen
        switch(option)
        {
            case 1:
                menu[0].action(stack1);
            break;
            case 2:
                menu[1].action(stack1);
            break;
            default:
                cout<<"invalid option"<<endl;
            break;
        }

    }
    
    return 0;
}

template<typename T,int N>
stack<T,N>::stack()
{
    this->size = N;
    top = size;
    for(auto& s : array)
    {
        s = static_cast<T>(0);
    }
    
}

template<typename T,int N>
void stack<T,N>::print_stack()const
{
    for(int i=0;i<size;i++)
    {
        if(top==i)
            cout<<">";
        cout<<"["<<array[i]<<']'<<endl;
    }
}

template<typename T,int N>
bool stack<T,N>::push(T value)
{
    if(top == 0)
        return false;

    array[--top] = value;
    return true;
}

template<typename T,int N>
bool stack<T,N>::pop(T *element)
{
    if(top == size)
        return false;
    
    *element = array[top++];
    return true;
}

template<typename T,int N>
void add(stack<T,N>& s)
{
    T temporary;
    cout<<"Value: ";
    cin>>temporary;
    if(s.push(temporary))
        cout<<"Value : "<<temporary<<" added"<<endl;
    else
        cout<<"Stack is already full"<<endl;
}

template<typename T,int N>
void pop(stack<T,N>& s)
{
    T temporary;
    if(s.pop(&temporary))
        cout<<"Value : "<<temporary<<" extracted"<<endl;
    else
        cout<<"Stack is already empty"<<endl;
}