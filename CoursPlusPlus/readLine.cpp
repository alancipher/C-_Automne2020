#include <sstream>
#include <string>
#include <fstream>

int main (){
std::ifstream infile("number.txt");
std::string line;
while (std :: getline (infile, line)){
std :: istringstream iss (line);
int a, b;
if  (!(iss>>a>>b)){
    break;
}else{
 std:: out << a << b << std::endl;
}
}

}
