package study.collection.java;

public class CollectionStudy {

	public static void main(String[] args) {
		
/*

컬렉션 프레임(기본 라이브러리 클래스): 요소 객체들의 저장소, 객체 컨테이너 -> 요소 개수에 따라 크기 자동 조절
(삽입 삭제에 따른 위치 자동 이동)
다양한 객체 삽입, 삭제, 검색 등 관리 용이
데이터 삭제 후 빈 공백 앞당겨 채움(배열의 경우 개발자가 직접 수행)
어레이리스트, 벡터 등 인터페이스 상속 후 재정의

자료구조의 클래스화

HashSet<E>   ->>   Set<E>                   =>>

ArrayList<E>
(Stack<E>  ->  ) Vector<E>   ->>   List<E>      =>> Collection<E>
LinkedList<E>

LinkedList<E>   ->>   Queue<E>              =>>

HashedMap<K, V>   =>>   Map<E>

컬렉션, 제네릭(generics) 기법으로 구현
(제네릭: 여러 종류 타입으로 변환, 사용할 수 있도록 클래스/메소드를 일반화 작성하는 기법)
-> 컬렉션의 요소는 객체만 가능(기본 int, char, double 등 기본 타입 사용불가)

<E>, <K>, <V> 타입 매개변수(일반화) <-> 구체화: Stack<integer>, Stack<String>

Vector<E>: E를 구체화해서 사용, 객체(+ null도 가능하나 중복은 안됨) 컨테이너 클래스,
유동적 길이 제한, 객체 삽입(맨 뒤, 중간), 객체 삭제(삭제 후 당겨 자리 이동)
Vector<E> 이름 = new Vector<E>();
Vector<E> 이름 = new Vector<생략가능>();
-> add();로 맨 뒤에 삽입(메모리 영역 주소 형태로 객체 저장)
-> get();로 검색

ArrayList<E>: E를 구체화해서 사용, 객체(+ null도 가능하나 중복은 안됨) 컨테이너 클래스,
가변 크기 배열 구현 클래스, 기본 타입은 박싱/언박싱으로 Wrapper 객체로 저장, 객체 삽입(맨 뒤, 중간)
객체 삭제(임의 위치 객체 삭제 가능), 벡터와 달리 스레드 동기화 기능 없음(싱글 스레드 환경 적합)
ArrayList<E> 이름 = new ArrayList<생략>();
ArrayList<E> 이름 = new ArrayList<E>(); 둘 다 가능


Iterator<E>: Vector<E>, ArrayList<E>, LinkedList<E>가 상속받는 인터페이스
<Iterator> 순서에 상관없이 자료 사용할 때 편함

HashMap<K,V>: 키와 값의 쌍으로 구성되는 컬렉션(파이썬의 딕셔너리??)
HashMap<Key, Value> 이름 = new HashMap<Key, Value>;

LinkedList<E>: List 인터페이스 구현한 컬렉션, 분산된 영역 연결

Collections 클래스: 컬렉션에 대해 연산 수행 후 컬렉션 리턴
sort(), reverse() 등

바이너리 써치?(2진 탐색):
정렬된 데이터 배열에 특정 값을 찾아내는 알고리즘
배열 중간 임의 값 n 선택, 원하는 값 X와 비교
X<n: n 기준 좌측의 데이터 탐색
X>n: n 기준 우측을 데이터 탐색
다시 n 값 임의 선택 후 비교
X를 찾을 때까지 과정 반복

제네릭 클래스: 클래스<T> -> 추후 구체화

타입 매개변수




 */
		
		
		
	}

}
