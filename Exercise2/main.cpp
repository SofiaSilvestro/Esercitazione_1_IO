#include <fstream>
#include <math.h>
#include <iostream>


// function to map values between intervals
double MapValues(double xf)
{
    const int xi = 1; // lower end of the first interval
    const int xs = 5; // upper end of the first interval
    const int Ni = -1; // lower end of the second interval
    const int Ns = 2; // upper end of the second interval

    // Nf = (((xf - xi) * (Ns - Ni)) / (xs - xi)) + Ni;

    return (((xf - xi) * (Ns - Ni)) / (xs - xi)) + Ni;
    // the result of this function is Nf, the map value
}

int main()
{
    std::string InputFileName = "data.csv"; // input file name
    std::ifstream ifs(InputFileName); // creates an ifstream object and open file

    std::string OutputFileName = "result.csv"; // output file name
    std::ofstream ofs(OutputFileName); // create an ofstream object

    if (ifs.fail())
    {
        std::cerr << "Error! Input file does not exist" << std::endl;
        return 1;
    }
    if (ofs.fail())
    {
        std::cerr << "Error! Output file has been created previously" << std::endl;
        return 1;
    }

    double xf = 0; // value read from the file
    int row = 0; // line index
    double sum = 0.0; // sum of the mapped values
    double Nf = 0.0; // from the function MapValues, mapped values
    double mean = 0.0; // mathematical average

    // the first row of the output file contain '# N Mean'
    ofs << "#\tN Mean" << std::endl;

    /** The loop is reading values from the file data.csv, then
     *  calculate the average of mapped values generated by the
     *  function MapValues, finally write them in a file result.csv **/
    while(ifs >> xf){
        Nf = MapValues(xf);
        sum += Nf ; // sum = sum + Nf
        row++;
        mean = sum / row;
        // print in file result.csv
        ofs << row << "\t" << std::scientific << mean << std::endl;

    }

    // closing input and output files
    ifs.close();
    ofs.close();

    std::cout << "Wow" << std::endl;

    return 0;
}
