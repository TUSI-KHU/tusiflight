#ifndef MATRIX_H
#define MATRIX_H
// Matrix 값으로 올 수있는 것은 정수, 실수형 및 복소수 자료형으로 제한합니다.
// 현재 나누기 연산은 별도로 정의하지 않음. 업데이트 예정

template<class T>
class Matrix{
public:
    Matrix(int row, int col) : _row(row), _col(col){
        _array = new T *[_row];
        for(int i=0;i<_row;i++){
            _array[i] = new T[_col];
            for(int j=0;j<_col;j++){
                _array[i][j] = 0;
            }
        }
    }

    Matrix(int row, int col, const T *array) : _row(row), _col(col) {
        _array = new T *[_row];
        for(int i=0;i<_row;i++){
            _array[i] = new T[_col];
            for(int j=0;j<_col;j++){
                _array[i][j] = 0;
            }
        }

        for (int i = 0; i < _row; i++) {
            for (int j = 0; j < _col; j++) {
                _array[i][j] = array[i * _col + j];
            }
        }
    }

    Matrix(const Matrix<T>& A) : _row(A._row), _col(A._col) {
        _array = new T*[_row];
        for (int i = 0; i < _row; i++) {
            _array[i] = new T[_col];
        }

        for (int i = 0; i < _row; i++) {
            for (int j = 0; j < _col; j++) {
                _array[i][j] = A._array[i][j];
            }
        }
    }

    ~Matrix(){
        for(int i=0;i<_row;i++){
            delete[] _array[i];
        }
    }

    int row(){
        return _row;
    }

    int col(){
        return _col;
    }

    T * operator [](int idx){
        return _array[idx];
    }

    Matrix<T> &transpose(){
        Matrix<T>* trans = new Matrix<T>(_col, _row);
        for(int i=0;i<_col;i++){
            for(int j=0;j<_row;j++){
                (*trans)[i][j] = _array[j][i];
            }
        }
        return *trans;
    }

    Matrix<T> operator+(const Matrix<T> &A) const{
        if(((_row==A._row)&&(_col==A._col))==false){
            int i;
        }
        else{
            Matrix<T> result(_row, _col);
            for(int i=0;i<_row;i++){
                for(int j=0;j<_col;j++){
                    result._array[i][j] = _array[i][j]+A._array[i][j];
                }
            }
            return result;
        }
    }
    
    Matrix<T> operator-(const Matrix<T> &A) const{
        if(((_row==A._row)&&(_col==A._col))==false){
            //error
            int i;
        }
        else{
            Matrix<T> result(_row, _col);
            for(int i=0;i<_row;i++){
                for(int j=0;j<_col;j++){
                    result._array[i][j] = _array[i][j]-A._array[i][j];
                }
            }
            return result;
        }
    }

    // 행렬 곱셈
    Matrix<T> operator*(const Matrix<T> &A) const {
        if(_col!=A._row){
            //error
            int i;
        }
        else{
            Matrix<T> result(_row, A._col);
            for(int i=0;i<_row;i++){
                for(int j=0;j<A._col;j++){
                    T sum = 0;
                    for(int k=0;k<_col;k++){
                        sum+=_array[i][k]*A._array[k][j];
                    }
                    result._array[i][j] = sum;
                }
            }
            return result;
        }
    }

    // 스칼라 곱셈 (e.g. H*4)
    Matrix<T> operator*(const T &A) const {
        Matrix<T> result(_row, _col);
        for(int i=0;i<_row;i++){
            for(int j=0;j<_col;j++){
                result._array[i][j] = _array[i][j] * A; 
            }
        }
        return result;
    }

    Matrix<T> & operator=(const Matrix<T> &A){
        _reset(A._row,A._col);
        for(int i=0;i<_row;i++){
            for(int j=0;j<_col;j++){
                _array[i][j] = A._array[i][j];
            }
        }
        return *this;
    }

    Matrix<T> & operator+=(const Matrix<T> &A){
        if(((_row==A._row)&&(_col==A._col))==false){
            //error
            int i;
        }
        else{
            for(int i=0;i<_row;i++){
                for(int j=0;j<_col;j++){
                    _array[i][j] += A._array[i][j];
                }
            }
            return *this;
        }
    }

    Matrix<T> & operator-=(const Matrix<T> &A){
        if(((_row==A._row)&&(_col==A._col))==false){
            //error
            int i;
        }
        else{
            for(int i=0;i<_row;i++){
                for(int j=0;j<_col;j++){
                    _array[i][j] -= A._array[i][j];
                }
            }
            return *this;
        }
    }

    Matrix<T> & operator*=(const Matrix<T> &A) {
        if(_col!=A._row){
            //error
            int i;
        }
        else{
            Matrix<T> result(_row, A._col);
            for(int i=0;i<_row;i++){
                for(int j=0;j<A._col;j++){
                    T sum = 0;
                    for(int k=0;k<_col;k++){
                        sum+=_array[i][k]*A._array[k][j];
                    }
                    result._array[i][j] = sum;
                }
            }
            *this = result;
            return *this;
        }
    }

    Matrix<T> & operator*=(const T &A) {
        for(int i=0;i<_row;i++){
            for(int j=0;j<_col;j++){
                _array[i][j] *= A; 
            }
        }
        return *this;
    }

private:
    T **_array;
    int _row;
    int _col;

    void _reset(int row, int col){
        for(int i=0;i<_row;i++){
            delete[] _array[i];
        }
        _row = row;
        _col = col;
        _array = new T *[_row];
        for(int i=0;i<_row;i++){
            _array[i] = new T[_col];
            for(int j=0;j<_col;j++){
                _array[i][j] = 0;
            }
        }
    }

    template<class U>
    friend Matrix<U> operator*(const U &, const Matrix<U> &);

    template<class U>
    friend Matrix<T> & operator*=(const T &, const Matrix<T> &);
};


// 스칼라곱 (e.g. 4*H)
template<class T>
Matrix<T> operator*(const T &A, const Matrix<T> &M) {
    Matrix<T> result(M._row, M._col);
    for(int i=0;i<M._row;i++){
        for(int j=0;j<M._col;j++){
            result._array[i][j] = A*M._array[i][j];
        }
    }
    return result;
}

template<class T>
Matrix<T> & operator*=(const T &A, const Matrix<T> &M) {
    for(int i=0;i<M._row;i++){
        for(int j=0;j<M._col;j++){
            M._array[i][j] *= A;
        }
    }
    return M;
}

#endif