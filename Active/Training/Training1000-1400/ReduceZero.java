import java.math.*;
import java.util.*;

public class ReduceZero {
	public static BigInteger lcm(String a, String b){
		BigInteger s = new BigInteger(a);
		BigInteger s1 = new BigInteger(b);
		BigInteger mul = s.multiply(s1);
		BigInteger gcd = s.gcd(s1);
		BigInteger lcm = mul.divide(gcd);
		return lcm;
	}
	public static void main(String[] args){
		String a = "99999999999999999";
        String b = "99999999999999999";
        
	}
}
