package study.exception.java;

public class ExceptionStudy {

	public static void main(String[] args) {
/*

������ ����
���� ����

�����߻� -> ���α׷� �ߴ�

����ó��: ����� ���� �Ǽ�, ������ �ڵ� �Ǽ��� ���α׷� ���Ḧ ���� �������� ����

���� ���� ����: NullPointException, ArrayIndexOutOfBoundsException,
NumberFormatException, ClassCastException ��

try {���� �߻���;}
catch(����Ŭ���� e) {���� ó����;}
finally {�׻���๮;}

���� catch:
try
catch(��������1 e){����ó��1;}
catch(��������2 e){����ó��2;}

catch(Exception e) => �ֻ��� ����ó�� ĳġ
���� �������� ��ġ�ؾ� �տ� ��ġ�� specific�� ����ó������ ĳġ��

catch(��������1 | ��������2){����ó��;} -> ����

throws: �޼ҵ� ����� ���� �ۼ�, �޼ҵ忡�� ó������ ���� ���ܸ� ȣ���� ������ ���� ���ѱ��
public void method1() throws ClassNotFoundException{
}
=> �߻��� ���ܸ� ȣ���� �޼ҵ�� ���ѱ��

����� ���� ����: ����� ���� ���� Ŭ���� ����
-> throws �����̸� => throw new �����̸�("��� ����");
-> 2���� ������(�⺻ ������, ���ܸ޽��� ����� String �Ű����� ������) ����

getMessage(): ���ܹ߻� �� ������ �Ű������� ����� �޼��� ����

printStackTrace(): ���ܹ߻� �ڵ� ���� ���� ���


 */
		
		String data1 = "100";
		String data2 = "a100";
		
		int value1 = Integer.parseInt(data1);
		System.out.println(value1);
		try {
		int value2 = Integer.parseInt(data2);
		System.out.println(value2); // <- NumberFormatException
		}
//		catch(Exception e){
//			System.out.println("������ �߻��߽��ϴ�.");
//		}
		catch(NumberFormatException e){
			System.out.println("���� Ÿ���� �ƴմϴ�.");
		}
		catch(ArrayIndexOutOfBoundsException e){
			System.out.println("���Ǵ� �ε��� ���� ���Դϴ�.");
		}
		System.out.println("��� �����մϴ�.");
		
	}

}
