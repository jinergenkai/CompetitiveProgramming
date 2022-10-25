# Importing all necessary libraries
import cv2
import os
  
# Read the video from specified path
cam = cv2.VideoCapture("D:\\lrig\\292570422_501127625104052_8402183993675486496_n.mp4")
  
try:
       
    # creating a folder named data
    if not os.path.exists('data'):
        os.makedirs('data')
  
# if not created then raise error
except OSError:
    print ('Error: Creating directory of data')
  
# frame
currentframe = 0   
    # reading from frame
ret,frame = cam.read()
# if video is still left continue creating images
name = 'D:\\lrig\\' + str(currentframe) + '.jpg'
print ('Creating...' + name)

# writing the extracted images
cv2.imwrite(name, frame)

# increasing counter so that it will
# show how many frames are created
currentframe += 1

  
# Release all space and windows once done
cam.release()
cv2.destroyAllWindows()