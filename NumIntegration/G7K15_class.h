class G7K15{
    private:
        double G7_, K15_, I_;
        double K_[15];
        double up_, down_;
        double int_, neg_int_;
        double error_;
        double tol_;

        typedef double (*fptr)(double x);

        fptr function_;

    public:
        // constructors
        G7K15(){}
        G7K15(double down, double up){
            down_ = down;
            up_ = up;
        }
        
        // setting things
        void set_function(fptr func){function_ = func;}

        // get values
        double get_integral(){return K15_;}

        void calc_subintervals();
        void calc_points();
        void calc_G7();
        void calc_K15();
};

inline void G7K15::calc_subintervals(){
    int_ = (up_ + down_)/2.;
    neg_int_ = (up_ - down_)/2.;
}

inline void G7K15::calc_points(){
    K_[0]  = function_(int_ - 9.9145537112081264e-1*neg_int_);
    K_[1]  = function_(int_ - 9.4910791234275853e-1*neg_int_);
    K_[2]  = function_(int_ - 8.6486442335976907e-1*neg_int_);
    K_[3]  = function_(int_ - 7.4153118559939444e-1*neg_int_);
    K_[4]  = function_(int_ - 5.8608723546769113e-1*neg_int_);
    K_[5]  = function_(int_ - 4.0584515137739717e-1*neg_int_);
    K_[6]  = function_(int_ - 2.0778495500789847e-1*neg_int_);
    K_[7]  = function_(int_);
    K_[8]  = function_(int_ + 2.0778495500789847e-1*neg_int_);
    K_[9]  = function_(int_ + 4.0584515137739717e-1*neg_int_);
    K_[10] = function_(int_ + 5.8608723546769113e-1*neg_int_);
    K_[11] = function_(int_ + 7.4153118559939444e-1*neg_int_);
    K_[12] = function_(int_ + 8.6486442335976907e-1*neg_int_);
    K_[13] = function_(int_ + 9.4910791234275853e-1*neg_int_);
    K_[14] = function_(int_ + 9.9145537112081264e-1*neg_int_);
}

inline void G7K15::calc_G7(){
    G7_ = int_*(
        1.2948496616886969e-1*K_[1] +
        2.7970539148927667e-1*K_[3] +
        3.8183005050511894e-1*K_[5] +
        4.1795918367346939e-1*K_[7] +
        3.8183005050511894e-1*K_[9] +
        2.7970539148927667e-1*K_[11] +
        1.2948496616886969e-1*K_[13]);
}

inline void G7K15::calc_K15(){
    K15_ = int_*(
        2.2935322010529225e-2*K_[0] +
        6.3092092629978553e-2*K_[1] +
        1.0479001032225018e-1*K_[2] +
        1.4065325971552592e-1*K_[3] +
        1.6900472663926790e-1*K_[4] +
        1.9035057806478541e-1*K_[5] +
        2.0443294007529889e-1*K_[6] +
        2.0948214108472783e-1*K_[7] +
        2.0443294007529889e-1*K_[8] +
        1.9035057806478541e-1*K_[9] +
        1.6900472663926790e-1*K_[10] +
        1.4065325971552592e-1*K_[11] +
        1.0479001032225018e-1*K_[12] +
        6.3092092629978553e-2*K_[13] +
        2.2935322010529225e-2*K_[14]);
}