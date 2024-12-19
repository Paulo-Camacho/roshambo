#include <iostream>
#include <string>
#include <vector>
int main()
{

    std::vector<std::string> game = {"rock", "paper", "sissors"}; 

    std::string answer;
    while(true)
{
    std::cout << game[0] << std::endl;
    std::cin >> answer;
    if(answer == "rock") 
    {    
        std::cout << "Alrighty";
    } 

} 
    return 0;

}
