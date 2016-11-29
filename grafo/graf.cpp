class Graph
{
protected :
    map <int , vector <int > > mapa ;

public :
    Graph ( const vector <int > &origen , const vector <int > &destino )
    {
        for( Size i = 0; i < origen.size (); i++ ) {
            int o = origen[i];
            int d = destino[i];
            mapa[o].push_back(d);
        }
    }

    const vector <int > &adyacente( const int key ) const
    {
        map <int,vector <int > >:: const_iterator it = mapa.find(key);
        if(it !=  mapa.end()) {
            return it-> second ;
        }
        cerr << "No hay nodo";
    }

    int cant_nodos (const int key ) const {
        return adyacente(key).size();
    }
};
////////////////////////
int main()
{
    //static_cast<Triangle *> (p)
    return 0;
}
