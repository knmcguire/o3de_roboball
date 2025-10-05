local ConstantRotate = {}

function ConstantRotate:OnActivate()
  self.tickHandler = TickBus.Connect(self)
end

function ConstantRotate:OnDeactivate()
  self.tickHandler:Disconnect()
  self.tickHandler = nil
end

function ConstantRotate:OnTick(deltaTime, timePoint)
  TransformBus.Event.RotateAroundLocalZ(self.entityId, deltaTime)
end

return ConstantRotate