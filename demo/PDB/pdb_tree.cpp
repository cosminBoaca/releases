#include <CGAL/PDB/PDB.h>
#include <boost/program_options.hpp>
#include <fstream>

int main(int argc, char *argv[]) {
  std::string input_file;
  bool print_help=false;
  bool verbose=false;
  boost::program_options::options_description o("Allowed options"), po, ao;
  o.add_options()
    ("help", boost::program_options::bool_switch(&print_help),
     "produce help message")
    ("verbose,v", boost::program_options::bool_switch(&verbose),
     "print out any errors that occur during reading of the pdb file.");

  po.add_options()
    ("input-pdb", boost::program_options::value< std::string>(&input_file),
     "input file");;
  ao.add(o).add(po);

  boost::program_options::positional_options_description p;
  p.add("input-pdb", 1);

  boost::program_options::variables_map vm;
  boost::program_options::store(boost::program_options::command_line_parser(argc, argv).
				options(ao).positional(p).run(), vm);
  boost::program_options::notify(vm);

  if (print_help || input_file.empty()) {
    std::cerr << "This program prints the contents of a PDB file.";
    std::cerr << "usage: " << argv[0] << " input-pdb output-pdb\n\n";
    std::cerr << o << "\n";
    return EXIT_FAILURE;
  }
 


  using namespace CGAL::PDB;
  std::ifstream in(input_file.c_str());
  PDB pdb(in, verbose);;
  for (PDB::Model_iterator it= pdb.models_begin(); it != pdb.models_end(); ++it){
    std::cout << "Model " << it->key() << ":" << std::endl;
    for (Model::Chain_iterator cit= it->model().chains_begin(); 
	 cit != it->model().chains_end(); ++cit) {
      std::cout << " Chain: " << static_cast<char>(cit->key().index());
      if (!cit->chain().name().empty()) {
	std::cout << cit->chain().name();
      }
      std::cout << std::endl;
      std::cout << "  " << cit->chain().number_of_atoms() << " atoms" << std::endl;
      std::cout << "  " << cit->chain().number_of_bonds() << " bonds" << std::endl;
    }
  }

  return EXIT_SUCCESS;
}
