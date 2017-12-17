import java.math.BigInteger;
import java.util.StringTokenizer;
import java.io.*;

public class maximum_java
{
	public static void main(String args[])
	{
		BigInteger arr[] = new BigInteger[1000000];
		BigInteger no_of_operations;
		BigInteger a,b,k,i,j,size;

		BufferedReader key_read = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer str_tokens = new StringTokenizer(key_read.readLine());

		size = new BigInteger(Integer.parseInt(str_tokens.nextToken()));
		no_of_operations = Integer.parseInt(str_tokens.nextToken());

		for(i=0;i<size;i++)
			arr[i] = 0;

		
		for(i=0;i<no_of_operations;i++)
		{
			str_tokens = new StringTokenizer(key_read.readLine());
			a = new BigInteger(parseInt(str_tokens.nextToken()));
			b = new BigInteger(parseInt(str_tokens.nextToken()));
			k = new BigInteger(parseInt(str_tokens.nextToken()));

			for(j=a;j<=b;j++)
				arr[j-1] += k;
		}

		BigInteger max = arr[0];

		for(i=1;i<size;i++)
		{
			if(max < arr[i])
				max = arr[i];
		}

		System.out.print(max);
	}
}