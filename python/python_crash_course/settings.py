
class Settings :

	def __init__(self) :
		self.screen_width = 1000 
		self.screen_height = 600
		self.bg_color = (230,230,230)
		self.ship_speed = 1.5 # 1 pixel  /click 

		# bullet settings 
		self.bullet_speed = 1.0 # 1 pixel / iteration
		self.bullet_width = 3 
		self.bullet_height = 15 
		self.bullet_color = (60,60,60)

		self.bullets_allowed = 3 