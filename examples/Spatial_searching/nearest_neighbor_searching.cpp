#include <CGAL/Simple_cartesian.h>
#include <CGAL/point_generators_2.h>
#include <CGAL/Orthogonal_k_neighbor_search.h>
#include <CGAL/Search_traits_3.h>
#include <CGAL/Projection_traits_xy_3.h>
#include <CGAL/Projection_traits_xz_3.h>
#include <CGAL/Projection_traits_yz_3.h>
#include <list>
#include <vector>
#include <cmath>

typedef CGAL::Simple_cartesian<double> K;
typedef K::Point_3 Point_d;
typedef CGAL::Projection_traits_xy_3<K> TreeTraitsXY;
typedef CGAL::Projection_traits_xz_3<K> TreeTraitsXZ;
typedef CGAL::Projection_traits_yz_3<K> TreeTraitsYZ;

template<class ProjectionTraits>
bool same_projection(const std::list<Point_d> &l1, const std::list<Point_d>& l2) {
  ProjectionTraits pt;
  if(l1.size() != l2.size())
    return false;
  std::list<Point_d>::const_iterator it1;
  std::list<Point_d>::const_iterator it2;
  for(it1 = l1.begin(), it2 = l2.begin(); it1 != l1.end(); it1++, it2++)
    if(pt.x(*it1) != pt.x(*it2) || pt.y(*it1) != pt.y(*it2)) 
      return false;
  return true;
} 

template<class ProjectionTraits>
void getPointList(CGAL::Orthogonal_k_neighbor_search<ProjectionTraits> ns, std::list<Point_d> &l) {
  l.clear();
  typename CGAL::Orthogonal_k_neighbor_search<ProjectionTraits>::iterator it;
  for(it = ns.begin(); it != ns.end(); it++)
    l.push_back(it->first);
} 

void create_points(std::list<Point_d>& ret, int fill_value, int x_idx, int y_idx, int size) {
  int i = 0;
  std::vector<std::vector<double> > m(size, std::vector<double>(3));
  for(std::vector<std::vector<double> >::iterator it = m.begin(); it != m.end(); it++, i++) {
    (*it)[0] = (*it)[1] = (*it)[2] = fill_value;
    (*it)[x_idx] = i;
    (*it)[y_idx] = i;
  } 
  for(std::vector<std::vector<double> >::iterator it = m.begin(); it != m.end(); it++) 
    ret.push_back(Point_d((*it)[0], (*it)[1], (*it)[2])); 
}  


template<class ProjectionTraits>
void test(unsigned int n, int x_idx, int y_idx, bool print_points = false) {
  const int size = 10;
  std::list<Point_d> p1, p2, ref;
  create_points(p1, 1, x_idx, y_idx, size);
  create_points(p2, 2, x_idx, y_idx, size);
  create_points(ref, 0, x_idx, y_idx, n);

  typename CGAL::Orthogonal_k_neighbor_search<ProjectionTraits>::Tree 
      t1(p1.begin(), p1.end()), t2(p2.begin(), p2.end());
  Point_d query(0, 0, 0);
  CGAL::Orthogonal_k_neighbor_search<ProjectionTraits> 
      ns1(t1, query, n), ns2(t2, query, n);

  getPointList(ns1, p1);
  getPointList(ns2, p2);

  assert(same_projection<ProjectionTraits>(p1, p2));
  assert(same_projection<ProjectionTraits>(ref, p2));

  if(print_points) {
    std::cout << "Points from first list\n";
    for(std::list<Point_d>::iterator it = p1.begin(); it != p1.end(); it++)
      std::cout << *it << '\n';
    std::cout << "Points from second list\n";
    for(std::list<Point_d>::iterator it = p2.begin(); it != p2.end(); it++)
      std::cout << *it << '\n';
  } 
} 

int main() {
  std::cout << "Test Projection_traits_xy_3\n";
  test<TreeTraitsXY>(3, 0, 1, true);
  std::cout << "\nTest Projection_traits_xz_3\n";
  test<TreeTraitsXZ>(3, 0, 2, true);
  std::cout << "\nTest Projection_traits_yz_3\n";
  test<TreeTraitsYZ>(3, 1, 2, true);
  return 0;
}

