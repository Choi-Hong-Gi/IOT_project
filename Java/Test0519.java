import java.util.Scanner;


public class Test0519 {
	   
   public static void main(String[] args) {
      Scanner scan = new Scanner(System.in);
      test tt = new test();
      System.out.print("�迭 ũ�⸦ �Է��ϼ��� >> ");
      int b= scan.nextInt();
      int[]arr=new int[b];
      //tt.sum(arr);
      
      for(int i =0; i<arr.length;i++) {
    	  System.out.print("������ �Է��ϼ��� >> ");
         arr[i]=scan.nextInt();
      }  
      System.out.println("�迭 �����̼�: " + tt.sum(arr));
      scan.close();
   } 
	      
}	   
	   
	
class test{
	long sum(int[] arr) {
		long sum=0;
         
		for (int i =0;i<arr.length;i++) {
			sum+=arr[i];
		}
		return sum;      
   }
	
}

