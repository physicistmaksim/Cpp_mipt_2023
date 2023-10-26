struct Base { }; 

struct D1 : Base { };

struct D2 : Base { }; 

struct D3 : D1, D2 { };

Base const * D1BaseToD2Base( Base const * base ) 
{
    D1 const * d1 = static_cast<D1 const *>(d1);
    D3 const * d3 = static_cast<D3 const *>(d1);
    return static_cast<D2 const *>(d3);
}