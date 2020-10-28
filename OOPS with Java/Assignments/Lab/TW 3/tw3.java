import java.util.Scanner;

class Rectangle{
	int length,breadth;
	Rectangle(int l,int b){
		length=l;
		breadth=b;
	}
	Rectangle(){
		//initialize an object
	}
	void changeDim(int length,int breadth) {
		this.length=length;
		this.breadth=breadth;
	}
	int area() {
		return length*breadth;
	}
}
public class tw3 {

	public static void main(String[] args) {
		Rectangle r1=new Rectangle(20,40);
		System.out.println("Area of rectangle for object r1 :"+r1.area());
		Scanner s=new Scanner(System.in);
		Rectangle r2=new Rectangle();
		System.out.println("Enter the length and breadth for rectangle: ");
		int length=s.nextInt();
		int breadth=s.nextInt();
		r2.changeDim(length, breadth);
		System.out.println("Area of rectangle for object r2 :"+r2.area());
	}
}