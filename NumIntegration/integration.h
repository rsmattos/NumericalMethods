void integrate(){
    G7K15 solver(0, 2);

    solver.set_function(sine);

    solver.adaptive_integral();

    std::cout << solver.get_integral() << std::endl;
}