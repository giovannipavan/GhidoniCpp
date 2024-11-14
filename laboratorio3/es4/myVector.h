class myVector
{
    int sz;           
    double *elem;     

public:
    myVector(int s);             // Costruttore
    int size() const { return sz; }  // Metodo per ottenere la dimensione

    // Operatori di accesso agli elementi
    double& operator[](int pos);      
    double operator[](int pos) const;  


    ~myVector() { delete[] elem; }
};

double safe_get(const myVector& v, int pos);
int safe_set(myVector& v, int pos, double value);

