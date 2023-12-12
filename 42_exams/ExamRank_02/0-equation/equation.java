public class equation {

	public static void main(String[] args) {
		fun(42);
	}

	static void fun(int n) {

		// AB + CA = n
		// 11a + 10c + b = n

		int a = -1, b = -1, c = -1;

		while (++a <= 9) {
			b = -1;
			while (++b <= 9) {
				c = -1;
				while (++c <= 9) {
					if (11 * a + 10 * b + c == n) {
						System.out.println("A = " + a + ", B = " + b + ", C = " + c);
					}
				}

			}
		}

	}

}
