import java.io.*;
import java.lang.*;
import java.util.*;
class ArrayStack{
    int top,size;
    int stack[];
    ArrayStack(int s){
        top=-1;
        size=s;
        stack=new int[size];
    }
    void push(int item){
         if(top==size-1){
           System.out.println("Stack Overflow!");
           return;
       }
        stack[++top]=item;
        System.out.println("Item Added : "+item);
    }
    void pop(){
       if(top==-1){
           System.out.println("Stack Underflow!");
           return;
       }
       System.out.println("Item popped : "+stack[top--]);
    }
    void display(){
        if(top==-1){
            System.out.println("Stack Empty!");
            return;
        }
        System.out.println("Stack items");
        for(int i=top;i>=0;i--){
            System.out.println("|"+stack[i]+"|");
        }
           System.out.println("|--|");
    }
}

class LinkedStack{

    private class Node{
        int data;       // holds data
        Node link;          // reference variable Node Type
    } 
    Node top;      // Head Node
    LinkedStack(){
        this.top=null;
    }
    void push(int item){
        Node temp = new Node();
        temp.data = item;
        temp.link = top;
        top = temp;
        System.out.println("Item Pushed : "+item);
    }
    void pop(){
        if(top==null){
            System.out.printf("\nStack Underflow");
            return;
        }
        System.out.println("Item popped : "+top.data);
        top = (top).link;
    }
    void display(){
        if(top==null){
            System.out.printf("\nStack Underflow");
            return;
        }
        Node temp=top;
        while(temp!=null){
            System.out.println("|"+temp.data+"|");
            temp = temp.link;
        }
         System.out.println("|--|");
    }
}

class TW5_B{
    public static void main(String[]args){
        ArrayStack s = new ArrayStack(10);
        System.out.println(" -- Array Stack --");
        s.push(10);
        s.push(14);
        s.push(13);
        s.push(74);
        s.push(51);
        s.display();
        s.pop();
        s.pop();
        s.display();
        LinkedStack c = new LinkedStack();
        System.out.println(" -- Linked Stack --");
        c.push(11);
        c.push(21);
        c.push(11);
        c.push(74);
        c.push(15);
        c.display();
        c.pop();
        c.pop();
        c.display();
    }
}