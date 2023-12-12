public class count_of_2 {
	public static void main(String[] args) {

		int a = count(25);
		System.out.println(a);
	}

	static int count(int n) {
		if (n <= 1) {
			return 0;
		} else {
			String result = "";
			for (int i = 2; i <= n; i++) {
				result += i;
			}
			System.out.println("result: " + result);
			int numOfTwo = 0;
			for (char ch : result.toCharArray()) {
				if (ch == '2') {
					numOfTwo++;
				}
			}
			return numOfTwo;
		}
	}

}
