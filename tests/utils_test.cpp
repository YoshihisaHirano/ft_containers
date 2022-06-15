#include <unistd.h>
#include <sys/time.h>
#include <stack>
#include <vector>
#include <iomanip>
#include <iterator>
#include "../stack.hpp"
#include "../vector.hpp"


#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

time_t timer() {
	struct timeval start = {};
	gettimeofday(&start, nullptr);
	time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return msecs_time;
}

void print_res(std::string test, std::vector<int> &s,
			   std::vector<int> &u, struct s_time_res &res)
{
	time_t s_time = res.std_end - res.std_start;
	time_t u_time = res.ft_end - res.ft_start;
	std::vector<int> error_res;

	std::string std_time_color = s_time <= u_time ? GREEN : RED;
	std::string ft_time_color = u_time <= s_time ? GREEN : RED;

	bool is_correct = true;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] != u[i])
		{
			error_res.push_back(s[i]);
			error_res.push_back(u[i]);
			error_res.push_back(i + 1);
			is_correct = false;
		}
	}

	std::string resultText = is_correct ? "OK" : "FALSE";
	std::cout
			<< std::setw(30) << std::setfill(' ') << std::left << test << (is_correct ? GREEN : RED)
			<< std::setw(10) << std::setfill(' ') << std::left << resultText << RESET
			<< ft_time_color << std::setw(15) << std::setfill(' ') << std::left << u_time << RESET
			<< std_time_color << std::setw(15) << std::setfill(' ') << std::left << s_time << RESET

			<< std::endl;

	if (!is_correct)
	{
		std::cout << "Incorrect results for " << test << " on test # " << error_res[2] << std::endl;
		std::cout << "std: " << error_res[0] << std::endl;
		std::cout << "ft: " << error_res[1] << std::endl;
	}
}

void print_header()
{

	std::cout
			<< std::setw(30) << std::setfill(' ') << std::left << "FUNCTION"
			<< std::setw(10) << std::setfill(' ') << std::left << "RESULT"
			<< std::setw(15) << std::setfill(' ') << std::left << "FT_TIME"
			<< std::setw(15) << std::setfill(' ') << std::left << "STD_TIME"

			<< std::endl;
}