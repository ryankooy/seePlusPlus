import numpy as np
from scipy.ndimage.filters import convolve, gaussian_filter
from imageio import imread
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

def canny_edge_detector(im, blur=1, high_thresh=91, low_thresh=31):
  im = np.array(im, dtype=float)

  # Reduce noise.
  im2 = gaussian_filter(im, blur)

  # Sobel filters to get gradients.
  im3h = convolve(im2, [[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]])
  im3v = convolve(im2, [[1, 2, 1], [0, 0, 0], [-1, -2, -1]])

  # Get gradient and direction.
  grad = np.power(np.power(im3h, 2.0) + np.power(im3v, 2.0), 0.5)
  theta = np.arctan2(im3v, im3h)
  theta_q = (np.round(theta * (5.0 / np.pi)) + 5) % 5 # Quantize direction.
  
  # Non-maximum suppression.
  grad_sup = grad.copy()
  for r in range(im.shape[0]):
    for c in range(im.shape[1]):
      if r == 0 or r == im.shape[0]-1 or c == 0 or c == im.shape[1]-1:
        grad_sup[r, c] = 0
        continue
      tq = theta_q[r, c] % 4
      if tq == 0:
        if grad[r, c] <= grad[r, c - 1] or grad[r, c] <= grad[r, c + 1]:
          grad_sup[r, c] = 0
      if tq == 1:
        if grad[r, c] <= grad[r - 1, c + 1] or grad[r, c] <= grad[r + 1, c - 1]:
          grad_sup[r, c] = 0
      if tq == 2:
        if grad[r, c] <= grad[r - 1, c] or grad[r, c] <= grad[r + 1, c]:
          grad_sup[r, c] = 0
      if tq == 3:
        if grad[r, c] <= grad[r - 1, c - 1] or grad[r, c] <= grad[r + 1, c + 1]:
          grad_sup[r, c] = 0

  # Double threshold.
  strong_edges = grad_sup > high_thresh
  thresh_edges = np.array(strong_edges, dtype=np.uint8) + (grad_sup > low_thresh)

  # Trace edges with hysteresis.
  final_edges = strong_edges.copy()
  curr_pixels = []
  for r in range(1, im.shape[0]-1):
    for c in range(1, im.shape[1]-1):
      if thresh_edges[r, c] != 1:
        continue
      local_patch = thresh_edges[r-1:r+2, c-1:c+2]
      patch_max = local_patch.max()
      if patch_max == 2:
        curr_pixels.append((r, c))
        final_edges[r, c] = 1
  while len(curr_pixels) > 0:
    new_pix = []
    for r, c in curr_pixels:
      for dr in range(-1, 2):
        for dc in range(-1, 2):
          if dr == 0 and dc == 0:
            continue
          r2 = r + dr
          c2 = c + dc
          if thresh_edges[r2, c2] == 1 and final_edges[r2, c2] == 0:
            new_pix.append((r2, c2))
            final_edges[r2, c2] = 1
    curr_pixels = new_pix
  return final_edges

if __name__ == '__main__':
  pic = 'C:/Users/Ry/Desktop/angstgals.jpg'
  im = imread(pic, pilmode='L')
  final_edges = canny_edge_detector(im)
  img = mpimg.imread(pic)
  implot = plt.imshow(img)
  plt.show()
  print(final_edges)
