#include <iostream>
#include <vector>


bool almostIncreasingSequence(std::vector<int> sequence)
{
	bool removed = false;
	int i = 0, j = 1;

	while (i < sequence.size() - 1 && j < sequence.size())
	{
		if (sequence[i] >= sequence[j])
		{
			if (removed == false)
			{
				removed = true;
			}
			else
			{
				return false;
			}
		}
		
		i++;
		j++;
	}

	return true;
}


int main()
{
	std::vector <int> sequence;
	int d;
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> d;
		sequence.push_back(d);
	}
	std::string ans;
	if (almostIncreasingSequence(sequence) == true)
	{
		ans = "true";
	}
	else
	{
		ans = "false";
	}
	std::cout << ans << std::endl;

}
