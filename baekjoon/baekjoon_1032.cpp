#include <iostream>
#include <string>

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	std::cin >> n;
	
	std::string s;
	std::cin >> s;
	
	std::string result = s;
	
	for (int i = 1; i < n; i++){
		
		std::string t;
		std::cin >> t;
		
		for (int j = 0; j < s.length(); j++){
			if (t[j] != result[j])	result[j] = '?';
		}
	}	

	std::cout << result;
	
	return 0;	
}
