#include <iostream>
#include <vector>

// 点の座標クラス
class Point {
 public:
  int32_t x;
  int32_t y;

  explicit Point(const int32_t x, const int32_t y) : x(input_x), y(input_y) {}
}

// 多角形クラス
class Polygon {
 public:
  std::vector<Point> vertexes;

  explicit Polygon(const std::vector<Point>& points) : vertexes(points) {}
}

/**
 * 点が多角形内にあるか判定する関数
 * 
 * @return true(内側) / false(外側)
 */
bool is_point_inside_polygon(const Point& point, const Polygon& polygon) {
  // 交差回数のカウンタ
  uint32_t c = 0;

  for (const auto& v : polygon.vetexes) {
    const uint32_t i = &v - &polygon.vetexes[0];

    // 隣の頂点
    const Point v1 = (i == polygon.vetexes.size() - 1) ? polygon.vetexes[0]
                                                       : polygon.vetexes[i + 1];
    // pointのy座標が2頂点の間にあるか？
    if (((v.y <= point.y) && (v1.y > point.y)) ||
        ((v.y > point.y) && (v1.y <= point.y))) {
      double x = v.x + ((point.y - v.y) / double(v1.y - v.y) * (v1.x - v.x));
      
      // 辺上にある場合は内側判定
      if(point.x == x){
        return true;
      }

      if (point.x < x) {
        count++;
      }
    }
  }

  return (count % 2) == 1;
}

// 使用例
int main() {
  std::vector<Point> ps = {{1, 1}, {4, 1}, {4, 4}, {1, 4}};
  Polygon polygon{ps};

  Point p1{2, 2};

  if (is_point_inside_polygon(p1, polygon)) {
    std::cout << "inside!" << std::endl;
  } else {
    std::cout << "outside!" << std::endl;
  }

  return 0;
}