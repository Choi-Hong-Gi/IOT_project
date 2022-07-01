package study.exception.java;

public class Account {

	private long balance;
	public Account() {}
	public long getBalance() {
		return balance;
	}

	public void deposit(int money) {
		balance += money;
	}

	public void withdraw(int money) throws BalanceInsufficeintException {
		if(balance < money) {
			throw new BalanceInsufficeintException("�ܰ����: "+(money-balance)+" ���ڶ�");
		}
		balance -= money;
	}


}