import java.util.*;

class Node{
  
   public int data;
   public  Node next;


   public Node(int data1 , Node next1){
        this.data = data1;
        this.next = next1;
    }
};


public class Demo {
    public static void main(String[] args){
    ArrayList<Integer> arr = new ArrayList<>();
    arr.add(2);
    arr.add(6);
    arr.add(9);
    arr.add(8);

    //assigning value to the node
    Node y1 = new Node(arr.get(0) , null);
    Node y2 = new Node(arr.get(1) , null);
    Node y3 = new Node(arr.get(2) , null);
    Node y4 = new Node(arr.get(3) , null);
   
    //linking of node
    y1.next = y2;
    y2.next =y3;
    y3.next = y4;

    System.out.println(y1.data +" " +y1.next);
   System.out.println(y2.data +" " +y2.next);
   System.out.println(y3.data +" " +y3.next);
   System.out.println(y4.data +" " +y4.next);

    
    }

}