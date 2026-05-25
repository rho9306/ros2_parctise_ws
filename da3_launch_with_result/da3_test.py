#!/usr/bin/env python3
import os
os.environ['HF_ENDPOINT'] = 'https://hf-mirror.com'

import torch
import numpy as np
import cv2
from depth_anything_3.api import DepthAnything3

IMAGE_PATH = '/home/rho922/da3_launch_with_result/1720513003.957466496.jpg'
RESULT_DIR = '/home/rho922/da3_launch_with_result/result'
MODEL_NAME = 'depth-anything/DA3-Large'

def main():
    print('Depth-Anything-3 Processing...')
    if not os.path.exists(IMAGE_PATH):
        print('Error: Image not found')
        return
    os.makedirs(RESULT_DIR, exist_ok=True)
    device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
    print(f'Using device: {device}')
    print('Loading model...')
    model = DepthAnything3.from_pretrained(MODEL_NAME)
    model = model.to(device)
    print('Processing image...')
    prediction = model.inference([IMAGE_PATH])
    
    # 获取深度图
    depth = prediction.depth[0]  # [H, W]
    print(f'Depth shape: {depth.shape}')
    print(f'Depth range: {depth.min():.4f} to {depth.max():.4f}')
    
    # 1. 保存原始深度数据
    np.savez(os.path.join(RESULT_DIR, 'depth.npz'), depth=depth)
    print('Depth data saved!')
    
    # 2. 生成彩虹色深度图 (热力图)
    depth_normalized = (depth - depth.min()) / (depth.max() - depth.min())
    depth_uint8 = (depth_normalized * 255).astype(np.uint8)
    depth_colormap = cv2.applyColorMap(depth_uint8, cv2.COLORMAP_JET)
    cv2.imwrite(os.path.join(RESULT_DIR, 'depth_rainbow.jpg'), depth_colormap)
    print('Rainbow depth map saved!')
    
    # 3. 生成灰度深度图
    depth_gray = ((1 - depth_normalized) * 255).astype(np.uint8)  # 近处亮，远处暗
    cv2.imwrite(os.path.join(RESULT_DIR, 'depth_gray.jpg'), depth_gray)
    print('Grayscale depth map saved!')
    
    # 4. 原样可视化（DA3 默认）
    vis_img = prediction.processed_images[0]
    cv2.imwrite(os.path.join(RESULT_DIR, 'depth_visualization.jpg'), cv2.cvtColor(vis_img, cv2.COLOR_RGB2BGR))
    print('Original visualization saved!')
    
    # 5. 生成对比图（原图 vs 彩虹深度）
    original = cv2.imread(IMAGE_PATH)
    original_resized = cv2.resize(original, (depth_colormap.shape[1], depth_colormap.shape[0]))
    comparison = np.hstack([original_resized, depth_colormap])
    cv2.imwrite(os.path.join(RESULT_DIR, 'comparison.jpg'), comparison)
    print('Comparison image saved!')
    
    print('Done!')

if __name__ == '__main__':
    main()
