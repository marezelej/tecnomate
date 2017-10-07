#include <string>

vector <string> pasaje(string & s, vector <string> & v)
{
	string limite = " ";
	size_t pos = 0;
	string sub;
	while(((pos = s.find(limite)) != std::string::npos))
	{
		sub = s.substr(0, pos);
		v.push_back(sub);
		s.erase(0, pos + limite.length()); //porque find() cuenta desde 1
	}
	v.push_back(s); //la ultima palabra queda dentro de s porque no tiene espacio al final
	s.clear();
	return v;
}

