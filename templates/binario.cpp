int main(){
    int resto, dividendo;
    cin >> dividendo;
    string resultado;
    do{
        resto = dividendo % 2;
        dividendo = dividendo / 2; 
        
        resultado = to_string(resto) + resultado;
    }while(dividendo != 0);
    
    int count, mayor = 0;
    for (auto c: resultado){
        if (c == '1')   count++;
        else{
            mayor = max(mayor,count);
            count = 0;
        }
    }   
   return    mayor = max(mayor,count);
