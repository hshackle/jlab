void readData(){

ifstream infile;
int array[20];
int i=0;
char cNum[10] ;
                infile.open ("poisson_data.csv", ifstream::in);
                if (infile.is_open())
                {
                        while (infile.good())
                        {
                                infile.getline(cNum, 256, ',');
                                array[i]= atoi(cNum) ;
                                i++ ;
                        }
                        infile.close();
                }
                else
                {
                        cout << "Error opening file";
                }
};

int main(){
  readData();
}

