package study.collection.java;

import java.util.Vector;

//class Point_1 {
//	int a, b;
//	
//	Point_1(int a, int b){
//		this.a = a;
//		this.b = b;
//	}
//	
//	@Override
//	public
//	String toString() {
//		return "(" + a + "," + b + ")";
//	}
//}


public class VectorPoint {

	public static void printVector(Vector<Integer> v) {
		for (int i = 0; i < v.size(); i++)
			System.out.print(v.get(i) + " ");
		
	}
	public static void main(String[] args) {
//		Vector<Point_1> v = new Vector<>();
//		
//		v.add(new Point_1(2,3));
//		v.add(new Point_1(-5,20));
//		v.add(new Point_1(30,-8));
//		
//		v.remove(1); //인덱스 1 요소 삭제
//		
//		for (int i = 0; i < v.size(); i++) {
//			Point_1 p = v.get(i);
//			System.out.println(p);
//			}
			
		Vector<Integer> vec = new Vector<>();
		vec.add(1465);
		vec.add(-246546);
		vec.add(3484);
		
		printVector(vec);
		
		
	}

}
