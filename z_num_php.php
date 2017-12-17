<?php>

	$test_cases = readline();

	if($test_cases>1 && $test_cases < 10000)
	{
		$flag1=1;
		for($i=0;$i<test_cases;$i++)
		{
			$a=readline();
			$b=readline();
			$n=readline()()

			if((1<$a<1000000000)&&(1<$b<1000000000)&&(1<$n<1000000000))
			{
				$flag2 = 1;
				for($j=0;$j<$n-1;$j++)
				{
					$c = $b + 2*$a;
					$a=$b;
					$b=$c;
				}

				$term[] = b;
			}
		}
	}

	if($flag1 == 1 && $flag2 == 1)
	{
		for($i=0;$i<$test_cases;$i++)
			$term[$i];
	}
?>