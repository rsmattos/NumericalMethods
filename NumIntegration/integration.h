void integrate(){
    G7K15 solver(0, 2);

    solver.set_function(exponential);

    solver.calc_subintervals();
    solver.calc_points();

    solver.calc_K15();

    std::cout << solver.get_integral() << std::endl;
}