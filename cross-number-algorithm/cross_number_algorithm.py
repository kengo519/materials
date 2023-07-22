def is_point_in_polygon(point, polygon):
    # 交差回数のカウンタ
    count = 0

    p_x = point[0]
    p_y = point[1]

    for i, v, in enumerate(polygon):
        # 頂点座標
        v_x = v[0]
        v_y = v[1]
        # 隣の頂点座標
        v1_x = polygon[0][0] if i == len(polygon)-1 else polygon[i+1][0]
        v1_y = polygon[0][1] if i == len(polygon)-1 else polygon[i+1][1]

        if((v_y <= p_y) and (v1_y > p_y)) or ((v_y > p_y) and (v1_y <= p_y)):
            x = v_x + ((p_y - v_y) / (v1_y - v_y)*(v1_x -v_x))
            # 辺上にある場合は内側判定
            if x == p_x:
                return True
            elif p_x < x:
                count += 1

    return bool(count%2 == 1)

# 使用例
if __name__ == '__main__':
    point = [2,2]
    polygon = [[1, 1], [4, 1], [4, 4], [1, 4]]

    if is_point_in_polygon(point, polygon):
        print("inside!")
    else:
        print("outside")
