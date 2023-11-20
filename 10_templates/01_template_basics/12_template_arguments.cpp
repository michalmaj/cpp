/*
 * Template Arguments:
 * Template arguments can, in general, automatically be deduced for function templates. The compiler deduces the
 * template arguments for the function arguments. From the user's perspective, function templates feel like functions.
 *
 * Conversions:
 *  - The compiler uses simple conversions for deducing the template arguments from the function arguments.
 *  - The compiler removes const or volatile from the function arguments and converts C-style arrays and functions to
 *    pointers.
 * Template argument deduction for function templates:
 *  template <typename T>
 *  void func(ParamType param)
 * Two datatype were deduced:
 *  - T
 *  - ParamType
 * ParamType can be:
 *  - Reference or pointer.
 *  - Universal reference (&&).
 *  - Value (copy).
 * 1. The parameter type is a reference or a pointer
 *  template <typenane T>
 *  void func(T& param);
 *  func(expr);
 * T ignores reference or pointer
 * Pattern matching on expr for T& or T
 *
 * 2. The parameter type is a universal reference (&&)
 *  template <typename T>
 *  void func(T&& param);
 *  func(expr);
 * expr is an lvalue: T and ParamType become lvalue references.
 * expr is a rvalue: T is deduced such as the ParamType is a reference (case 1)
 *
 * 3. Parameter type is a value (copy)
 *  template <typename T>
 *  void func(T param);
 *  func(expr);
 * expr is a reference: the reference (pointer) of the argument is ignored.
 * expr is cont or volatile: const or volatile is ignored.
 *
 * Template Arguments (C++17)
 * The constructor can deduce its template arguments from its function arguments.
 * Template Argument deduction for a constructor is available since C++17, but for function templates since C++98.
 *  std::pair<int, double> myPair(1998, 1.23);
 *  std::pair myPair(2017, 1.23);
 * Many if the make_ functions such as std::make_pair are not necessary any more:
 *  auto myPair = std::make_pair(2017, 1.23);
 *
 * Argument Deduction
 * The types of function arguments have to be exact, otherwise, no conversion takes place:
 *  template <typename T>
 *  bool isSmaller(T fir, T sec){
 *      return fir < sec;
 *  }
 *  isSmaller(1, 5LL); // Error int != long long int
 * Providing a second template parameter makes this example work
 *  bool isSmaller(T fir, U sec){
 *      return fir < sec;
 *  }
 *  isSmaller(1, 5LL); // OK
 *
 * Explicit Template Arguments
 * Unlike in line isSmaller(1, 5LL); in the example above, sometimes the template argument types need to be explicitly
 * specified. This is necessary in the following ceses:
 *  - if the template argument cannot be deduced from the function argument;
 *  - if a specific instance of a function template is needed.
 *  template <typename R, typename T, typename U>
 *  R add(T fir, U sec){
 *      return fir * sec;
 *  }
 *  add<long, long, int>(1000000, 1000000LL);
 * Missing template arguments are automatically derived from the function arguments.
 *
 * DefaultTemplate Arguments
 * The default for template parameters can be specified for class templates and function templates. If a template
 * parameter has a default parameter, all subsequent template parameters also need a default argument.
 *  template <typename T, typename Pred = std::less<T>>
 *  bool isSmaller(T fir, T sec, Pred pred = Pred()){
 *      return pred(fir, sec);
 *  }
 */