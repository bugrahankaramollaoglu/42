import java.util.Arrays;

public class isAnagram {
	public static void main(String[] args) {
		String a = "bugra";
		String b = "gruba";
		System.out.println(anagramChecker(a, b));
	}

	static int anagramChecker(String a, String b) {

		if (a.length() != b.length())
			return 0;

		char[] arr_a = a.toCharArray();
		char[] arr_b = b.toCharArray();

		Arrays.sort(arr_a); // this is how you sort an
		Arrays.sort(arr_b); // an array in Java

		// if (arr_a.equals(arr_b))
		// return 1;

		if (Arrays.equals(arr_a, arr_b))
			return 1;

		return 0;
	}
}
